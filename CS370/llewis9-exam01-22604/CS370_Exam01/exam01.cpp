// CS370 Exam01 - Fall 2020
// Name: Le Quient Lewis II


#include "stdio.h"
#include <vector>
#include "vgl.h"
#include "objloader.h"
#include "utils.h"
#include "vmath.h"
#define DEG2RAD (M_PI/180.0)
#define TABLE_SIZE 4.0f
#define TARGET_Y 0.0f
#define TARGET_X -0.5f
#define TARGET_Z 1.0f
#define CIRCLE_RAD 2.3f
#define NUM_MODES 7

using namespace vmath;
using namespace std;

enum VAO_IDs {Cube, Sphere, Pyramid, Cylinder, Target, NumVAOs};
enum Buffer_IDs {SpherePosBuffer, CubePosBuffer, PyrPosBuffer, PyrColBuffer, PyrIndexBuffer, CylinderColBuffer, CylinderIndexBuffer, TargPosBuffer, TargColBuffer, NumBuffers};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

GLint numVertices[2] = {0, 0};
GLint meshPosCoords = 4;
GLint pyrPosCoords = 3;
GLint pyrColCoords = 4;
GLint pyrIndices = 0;
vec4 table_color = {1.0f, 1.0f, 1.0f, 1.0f};
vec4 sphere_color = {1.0f, 1.0f, 0.0f, 1.0f};

// Declare projection matrix
mat4 proj_matrix = mat4().identity();
mat4 camera_matrix = mat4().identity();
mat4 model_matrix = mat4().identity();

// Camera
vec3 eye = {1.0f, 1.0f, 1.0f};
vec3 center = {0.0f, 0.0f, 0.0f};
vec3 up = {0.0f, 1.0f, 0.0f};

// Shader variables
GLuint mesh_program;
GLuint mesh_vPos;
GLuint mesh_vCol;
GLuint mesh_model_mat_loc;
GLuint mesh_proj_mat_loc;
GLuint mesh_cam_mat_loc;
GLuint grad_program;
GLuint grad_vPos;
GLuint grad_vCol;
GLuint grad_model_mat_loc;
GLuint grad_proj_mat_loc;
GLuint grad_cam_mat_loc;
const char *vertex_shader = "../color_grad.vert";
const char *mesh_shader = "../color_mesh.vert";
const char *frag_shader = "../color.frag";
const char *models[3] = {"../models/cube.obj", "../models/sphere.obj", "../models/cylinder.obj"};

// Global state
GLfloat pyr_angle = 0.0;
GLdouble elTime = 0.0;
GLdouble rpm = 10.0;
vec3 axis = {1.0f, 1.0f, 1.0f};

// Global spin variables - DO NOT MODIFY
GLfloat spin_theta = 0.0f;
GLboolean spin_flag = true;
GLfloat rev_theta = 0.0f;
GLboolean rev_flag = true;

// Global spherical coord values
GLfloat azimuth = 45.0f;
GLfloat daz = 2.0f;
GLfloat elevation = 54.7f;
GLfloat del = 2.0f;
GLfloat radius = 1.732f;
GLfloat dir = 1.0f;

// Global screen dimensions
GLint ww,hh;
int mode = 7;

void build_geometry( );
void build_table();
void build_pyramid();
void build_sphere();
void display( );
void render_scene( );
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow *window, int button, int action, int mods);
void draw_obj(GLuint VAO, GLuint Buffer, int numVert, vec4 color);
void draw_table();
void draw_target();
void draw_pyramid();

int main(int argc, char**argv)
{
	// Create OpenGL window
	GLFWwindow* window = CreateWindow("Exam 1 Fall 2020");
    if (!window) {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    } else {
        printf("OpenGL window successfully created\n");
    }

    // Store initial window size in global variables
    glfwGetFramebufferSize(window, &ww, &hh);

    // Register callbacks
    glfwSetKeyCallback(window,key_callback);
    glfwSetMouseButtonCallback(window, mouse_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Get initial time
    elTime = glfwGetTime();

    // Create geometry buffers
    build_geometry();
    
    // Load shaders and associate variables
    // Mesh shader (uniform color)
	ShaderInfo mesh_shaders[] = { {GL_VERTEX_SHADER, mesh_shader},{GL_FRAGMENT_SHADER, frag_shader},{GL_NONE, NULL} };
	mesh_program = LoadShaders(mesh_shaders);
	mesh_vPos = glGetAttribLocation(mesh_program, "vPosition");
    mesh_vCol = glGetUniformLocation(mesh_program, "vColor");
    mesh_model_mat_loc = glGetUniformLocation(mesh_program, "model_matrix");
    mesh_proj_mat_loc = glGetUniformLocation(mesh_program, "proj_matrix");
    mesh_cam_mat_loc = glGetUniformLocation(mesh_program, "camera_matrix");

    // Gradient shader (per vertex color)
    ShaderInfo grad_shaders[] = { {GL_VERTEX_SHADER, vertex_shader},{GL_FRAGMENT_SHADER, frag_shader},{GL_NONE, NULL} };
    grad_program = LoadShaders(grad_shaders);
    grad_vPos = glGetAttribLocation(grad_program, "vPosition");
    grad_vCol = glGetAttribLocation(grad_program, "vColor");
    grad_model_mat_loc = glGetUniformLocation(grad_program, "model_matrix");
    grad_proj_mat_loc = glGetUniformLocation(grad_program, "proj_matrix");
    grad_cam_mat_loc = glGetUniformLocation(grad_program, "camera_matrix");

    // Enable depth test
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

    // Set initial camera position
    GLfloat x, y, z;
    x = (GLfloat)(radius*sin(azimuth*DEG2RAD)*sin(elevation*DEG2RAD));
    y = (GLfloat)(radius*cos(elevation*DEG2RAD));
    z = (GLfloat)(radius*cos(azimuth*DEG2RAD)*sin(elevation*DEG2RAD));
    eye = vec3(x, y, z);

    // Start loop
    while ( !glfwWindowShouldClose( window ) ) {
    	// Draw graphics
        display();
        // Update other events like input handling
        glfwPollEvents();
        // Update angle based on time for fixed rpm
        GLdouble curTime = glfwGetTime();
        if (mode > 3)
        {
            if (spin_flag)
            {
        		/******************************************/
                /*       INSERT (f) CODE HERE             */
                /******************************************/
                spin_theta += 1.0f*(curTime-elTime)*(rpm/60.0f)*360.0f;
            }
            if (mode > 4)
            {
                if (rev_flag)
                {
                    /******************************************/
                    /*       INSERT (i) CODE HERE             */
                    /******************************************/
                    rev_theta += -1.0f*(curTime-elTime)*(rpm/60.0f)*360.0f;
                }
            }
        }
        elTime = curTime;
        // Swap buffer onto screen
        glfwSwapBuffers( window );
    }

    // Close window
    glfwTerminate();
    return 0;
}

void build_geometry( )
{
    // Generate vertex arrays and buffers
	glGenVertexArrays(NumVAOs, VAOs);
    glGenBuffers(NumBuffers, Buffers);

    build_pyramid();

    build_sphere();

    build_table();
}

void display( )
{
	// Clear window and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Compute anisotropic scaling
    GLfloat xratio = 1.0f;
    GLfloat yratio = 1.0f;

    // If taller than wide adjust y
    if (ww <= hh)
    {
        yratio = (GLfloat)hh / (GLfloat)ww;
    }
        // If wider than tall adjust x
    else if (hh <= ww)
    {
        xratio = (GLfloat)ww / (GLfloat)hh;
    }

    // Set projection matrix
    proj_matrix = mat4().identity();
    proj_matrix = ortho(-6.0f*xratio, 6.0f*xratio, -6.0f*yratio, 6.0f*yratio, -6.0f, 6.0f);
    glUniformMatrix4fv(grad_proj_mat_loc, 1, GL_FALSE, proj_matrix);
    glUniformMatrix4fv(mesh_proj_mat_loc, 1, GL_FALSE, proj_matrix);

    // Set camera matrix
    camera_matrix = mat4().identity();
    camera_matrix = lookat(eye, center, up);
    glUniformMatrix4fv(grad_cam_mat_loc, 1, GL_FALSE, camera_matrix);
    glUniformMatrix4fv(mesh_cam_mat_loc, 1, GL_FALSE, camera_matrix);

    // Render objects
	render_scene();

	// Flush pipeline
	glFlush();
}

void render_scene( ) {
    // Declare transformation matrices
    model_matrix = mat4().identity();
    mat4 scale_matrix = mat4().identity();
    mat4 rot_matrix = mat4().identity();
    mat4 rot2_matrix = mat4().identity();
    mat4 trans_matrix = mat4().identity();
    mat4 trans2_matrix = mat4().identity();
    mat4 trans3_matrix = mat4().identity();

    if (mode == 0) {
        draw_table();
    }
    // (c) Pyramid instance model
    else if (mode == 1) {
        draw_table();
        draw_pyramid();
    }
    // (d) Basic pyramid centered at origin
    else if (mode==2)
    {
        draw_table();

        /******************************************/
        /*       INSERT (d) CODE HERE             */
        /******************************************/
        trans_matrix = translate(-0.50f, 0.00f, -0.50f);
        model_matrix = trans_matrix;
        draw_pyramid();

    }
    // (e) Pyramid located at target location
    else if (mode==3)
    {
        draw_table();

        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        model_matrix = trans_matrix;

        draw_target();

        /******************************************/
        /*       INSERT (e) CODE HERE             */
        /******************************************/

        rot_matrix = rotate(180.00f, 0.00f, 0.00f, 1.00f);
        trans_matrix = translate(TARGET_X + 0.50f, -1.00f, TARGET_Z - 0.50f);
        model_matrix = rot_matrix*trans_matrix;

        draw_pyramid();
    }
    // (f) Spinning pyramid at target location
    else if (mode==4)
    {
        draw_table();

        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        model_matrix = trans_matrix;

        draw_target();

        /******************************************/
        /*       INSERT (f) CODE HERE             */
        /******************************************/

        rot_matrix = rotate(180.00f, 0.00f, 0.00f, 1.00f);
        rot2_matrix = rotate(spin_theta, 0.00f, 1.00f, 0.00f);
        trans_matrix = translate(TARGET_X + 0.50f, -1.00f, TARGET_Z - 0.50f);
        trans2_matrix = translate(-0.50f, 0.00f, -0.50f);
        trans3_matrix = translate(-0.50f, 0.00f, 0.50f);

        model_matrix = trans3_matrix*rot_matrix*trans_matrix*rot2_matrix*trans2_matrix;

        draw_pyramid();
    }
    // (h) Spinning pyramid at target location and sphere at origin
    else if (mode==5)
    {
        draw_table();

        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        model_matrix = trans_matrix;

        draw_target();

        /******************************************/
        /*       INSERT (h) CODE HERE             */
        /******************************************/

        rot_matrix = rotate(180.00f, 0.00f, 0.00f, 1.00f);
        rot2_matrix = rotate(spin_theta, 0.00f, 1.00f, 0.00f);
        trans_matrix = translate(TARGET_X + 0.50f, -1.00f, TARGET_Z - 0.50f);
        trans2_matrix = translate(-0.50f, 0.00f, -0.50f);
        trans3_matrix = translate(-0.50f, 0.00f, 0.50f);

        model_matrix = trans3_matrix*rot_matrix*trans_matrix*rot2_matrix*trans2_matrix;

        draw_pyramid();

        scale_matrix = scale(0.50f,0.50f,0.50f);
        model_matrix = scale_matrix;

        glUniformMatrix4fv(mesh_model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniform4fv(mesh_vCol, 1, sphere_color);


        draw_obj(VAOs[Sphere], Buffers[SpherePosBuffer], numVertices[Sphere], sphere_color);
    }
    // (i) Spinning pyramid and revolving sphere at target location
    else if (mode==6)
    {
        draw_table();

        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        model_matrix = trans_matrix;

        draw_target();

        /******************************************/
        /*       INSERT (i) CODE HERE             */
        /******************************************/

        rot_matrix = rotate(180.00f, 0.00f, 0.00f, 1.00f);
        rot2_matrix = rotate(spin_theta, 0.00f, 1.00f, 0.00f);
        trans_matrix = translate(TARGET_X + 0.50f, -1.00f, TARGET_Z - 0.50f);
        trans2_matrix = translate(-0.50f, 0.00f, -0.50f);
        trans3_matrix = translate(-0.50f, 0.00f, 0.50f);

        model_matrix = trans3_matrix*rot_matrix*trans_matrix*rot2_matrix*trans2_matrix;

        draw_pyramid();

        rot_matrix = rotate(rev_theta, 0.00f, 1.00f, 0.00f);
        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        trans2_matrix = translate(-2.250f, 0.50f, TARGET_Y);
        scale_matrix = scale(0.50f,0.50f,0.50f);
        model_matrix = trans_matrix*rot_matrix*trans2_matrix*scale_matrix;

        glUniformMatrix4fv(mesh_model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniform4fv(mesh_vCol, 1, sphere_color);

        draw_obj(VAOs[Sphere], Buffers[SpherePosBuffer], numVertices[Sphere], sphere_color);
    }
    // (j) Extra credit: Spinning pyramid and revolving "barbell" at target location
    else if (mode==7)
    {
        draw_table();

        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        model_matrix = trans_matrix;

        draw_target();

        /******************************************/
        /*       INSERT (j) CODE HERE             */
        /******************************************/

        rot_matrix = rotate(180.00f, 0.00f, 0.00f, 1.00f);
        rot2_matrix = rotate(spin_theta, 0.00f, 1.00f, 0.00f);
        trans_matrix = translate(TARGET_X + 0.50f, -1.00f, TARGET_Z - 0.50f);
        trans2_matrix = translate(-0.50f, 0.00f, -0.50f);
        trans3_matrix = translate(-0.50f, 0.00f, 0.50f);

        model_matrix = trans3_matrix*rot_matrix*trans_matrix*rot2_matrix*trans2_matrix;

        draw_pyramid();

        rot_matrix = rotate(rev_theta, 0.00f, 1.00f, 0.00f);
        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        trans2_matrix = translate(-2.250f, 0.50f, TARGET_Y);
        scale_matrix = scale(0.50f,0.50f,0.50f);
        model_matrix = trans_matrix*rot_matrix*trans2_matrix*scale_matrix;

        glUniformMatrix4fv(mesh_model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniform4fv(mesh_vCol, 1, sphere_color);

        draw_obj(VAOs[Sphere], Buffers[SpherePosBuffer], numVertices[Sphere], sphere_color);

        rot_matrix = rotate(rev_theta, 0.00f, 1.00f, 0.00f);
        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        trans2_matrix = translate(2.250f, 0.50f, TARGET_Y);
        scale_matrix = scale(0.50f,0.50f,0.50f);
        model_matrix = trans_matrix*rot_matrix*trans2_matrix*scale_matrix;

        glUniformMatrix4fv(mesh_model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniform4fv(mesh_vCol, 1, sphere_color);

        draw_obj(VAOs[Sphere], Buffers[SpherePosBuffer], numVertices[Sphere], sphere_color);

        rot_matrix = rotate(rev_theta, 0.00f, 1.00f, 0.00f);
        trans_matrix = translate(TARGET_X, TARGET_Y, TARGET_Z);
        trans2_matrix = translate(0.00f, 0.50f, TARGET_Y);
        scale_matrix = scale(2.50f,0.10f,0.10f);
        model_matrix = trans_matrix*rot_matrix*trans2_matrix*scale_matrix;

        glUniformMatrix4fv(mesh_model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniform4fv(mesh_vCol, 1, sphere_color);

        draw_obj(VAOs[Cube], Buffers[CubePosBuffer], numVertices[Cube], vec4(0.00f, 0.00f, 0.00f, 0.00f));

    }
}

void build_pyramid() {
    // Bind pyramid vertex array object
    glBindVertexArray(VAOs[Pyramid]);

    // Define vertices
    GLfloat vertices[][3] = {
            {0.0f, 0.0f, 0.0f}, // 0
            {1.0f, 0.0f, 0.0f}, // 1
            {1.0f, 0.0f, 1.0f}, // 2
            {0.0f, 0.0f, 1.0f}, // 3
            {0.5f, 1.0f, 0.5f}, // 4
    };

    // Define pyramid colors (per vertex)
    GLfloat colors[][4] = {
            {1.0f, 0.0f, 0.0f, 1.0f}, // 0
            {1.0f, 0.0f, 0.0f, 1.0f}, // 1
            {1.0f, 0.0f, 0.0f, 1.0f}, // 2
            {1.0f, 0.0f, 0.0f, 1.0f}, // 3
            {1.0f, 1.0f, 0.0f, 1.0f}, // 4
    };

    // Define pyramid face indices (ensure proper orientation)
    GLushort indices[] = {
        0,1,2,2,3,0, // base
        0,4,1,
        1,4,2,
        2,4,3,
        3,4,0
    };

    pyrIndices = sizeof(indices);

    glGenBuffers(NumBuffers, Buffers);

    // Bind pyramid positions
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[PyrPosBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Bind pyramid colors
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[PyrColBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    // Bind pyramid indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Buffers[PyrIndexBuffer]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void draw_pyramid(){
    // Select gradient shader program
    glUseProgram(grad_program);

    // Bind Pyramid vertex array object
    glBindVertexArray(VAOs[Pyramid]);

    // Bind attribute buffers and set gradient vertex attributes
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[PyrPosBuffer]);
    glVertexAttribPointer(grad_vPos, pyrPosCoords, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(grad_vPos);

    glBindBuffer(GL_ARRAY_BUFFER, Buffers[PyrColBuffer]);
    glVertexAttribPointer(grad_vCol, pyrColCoords, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(grad_vCol);

    // Pass projection, camera, and model matrix to grad shader
    glUniformMatrix4fv(grad_proj_mat_loc, 1, GL_FALSE, proj_matrix);
    glUniformMatrix4fv(grad_cam_mat_loc, 1, GL_FALSE, camera_matrix);
    glUniformMatrix4fv(grad_model_mat_loc, 1, GL_FALSE, model_matrix);
    // Draw indexed pyramid
    glDrawElements(GL_TRIANGLES, pyrIndices, GL_UNSIGNED_SHORT, NULL);

}

void build_sphere() {
    // Model vectors
    vector<vec4> mesh_vertices;
    vector<vec2> mesh_uvCoords;
    vector<vec3> mesh_normals;
    // Bind sphere vertex array object
    glBindVertexArray(VAOs[Sphere]);

	/******************************************/
    /*       INSERT (g) CODE HERE             */
    /******************************************/

    loadOBJ(models[Sphere], mesh_vertices, mesh_uvCoords, mesh_normals);
    numVertices[Sphere] = mesh_vertices.size();

    // Bind sphere positions
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[SpherePosBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*meshPosCoords*numVertices[Sphere], mesh_vertices.data(), GL_STATIC_DRAW);

}

#include "examfunc.cpp"