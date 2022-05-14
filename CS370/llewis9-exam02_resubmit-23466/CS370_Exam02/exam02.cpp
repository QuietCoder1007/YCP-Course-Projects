// CS370 Exam02
// Fall 2020

/******************************************/
/*       INSERT (a) CODE HERE             */
/******************************************/
// Name:  Le Quient Lewis II

#include "stdio.h"
#include <vector>
#include "vgl.h"
#include "objloader.h"
#include "utils.h"
#include "vmath.h"
#include "lighting.h"
#define DEG2RAD (M_PI/180.0)
#define TABLE_SIZE 5.0f
#define POT_X 0.0f
#define POT_Z 0.0f
#define STACK_X 3.0f
#define STACK_Z -3.0f
#define CUP_X 2.0f
#define CUP_Z 0.0f
#define NUM_MODES 8

using namespace vmath;
using namespace std;

enum VAO_IDs {Cube, Donut, Teapot, Cylinder, NumVAOs};
enum Buffer_IDs {PosBuffer, NormBuffer, NumObjBuffers};
enum LightBuffer_IDs {LightBuffer, NumLightBuffers};
enum MaterialBuffer_IDs {MaterialBuffer, NumMaterialBuffers};
enum MaterialNames {GreyPlastic, Brass, Dough, YellowAcrylic, RedAcrylic, Coffee};

GLuint VAOs[NumVAOs];
GLuint ObjBuffers[NumVAOs][NumObjBuffers];
GLuint LightBuffers[NumLightBuffers];
GLuint MaterialBuffers[NumMaterialBuffers];

GLint numVertices[NumVAOs];
GLint posCoords = 4;
GLint normCoords = 3;

vector<const char *> objFiles = {"../models/cube.obj", "../models/donut.obj", "../models/teapot.obj", "../models/cylinder.obj"};

// Camera
vec3 eye = {1.0f, 1.0f, 1.0f};
vec3 center = {0.0f, 0.0f, 0.0f};
vec3 up = {0.0f, 1.0f, 0.0f};

// Shader variables
GLuint program;
GLuint vPos;
GLuint vNorm;
GLuint proj_mat_loc;
GLuint camera_mat_loc;
GLuint model_mat_loc;
GLuint norm_mat_loc;
GLuint lights_block_idx;
GLuint materials_block_idx;
GLuint material_loc;
GLuint num_lights_loc;
GLuint eye_loc;
const char *vertex_shader = "../phong.vert";
const char *frag_shader = "../phong.frag";

// Global state
mat4 proj_matrix;
mat4 camera_matrix;
mat4 model_matrix;
mat4 normal_matrix;
vector<LightProperties> Lights;
vector<MaterialProperties> Materials;
GLuint numLights;
GLdouble elTime = 0.0;

// Global variables - DO NOT MODIFY
GLfloat ppm = 6.0f;
GLfloat pot_theta = 0.0f;
GLboolean tipping = true;
GLint pour_dir = -1.0;
GLfloat pour_ang = -45.0f;
GLboolean pouring = false;
GLfloat coffee_y = 0.0f;
GLfloat coffee_fill = 1000.0f;
vec4 whiteLightPos = {1.0f, 4.0f, 1.0f, 1.0f};

// Global spherical coord values
GLfloat azimuth = 45.0f;
GLfloat daz = 2.0f;
GLfloat elevation = 54.7f;
GLfloat del = 2.0f;
GLfloat radius = 1.732f;

// Global screen dimensions
GLint ww,hh;
int mode = 0;

void build_geometry( );
void build_lights();
void build_materials();
void display( );
void render_scene( );
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
void mouse_callback(GLFWwindow *window, int button, int action, int mods);
void load_object(GLuint obj);
void draw_object(GLuint obj);
void draw_table();

int main(int argc, char**argv)
{
	// Create OpenGL window
	GLFWwindow* window = CreateWindow("Exam 2 Fall 2020");
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

    // Create geometry buffers
    build_geometry();
    // Create light buffers
    build_lights();
    // Create material buffers
    build_materials();
    
    // Load shaders and associate variables
	ShaderInfo shaders[] = { {GL_VERTEX_SHADER, vertex_shader},{GL_FRAGMENT_SHADER, frag_shader},{GL_NONE, NULL} };
	program = LoadShaders(shaders);
    // Select shader program and associate shader variables
    vPos = glGetAttribLocation(program, "vPosition");
    vNorm = glGetAttribLocation(program, "vNormal");
    camera_mat_loc = glGetUniformLocation(program, "cam_matrix");
    model_mat_loc = glGetUniformLocation(program, "model_matrix");
    proj_mat_loc = glGetUniformLocation(program, "proj_matrix");
    norm_mat_loc = glGetUniformLocation(program, "norm_matrix");
    lights_block_idx = glGetUniformBlockIndex(program, "LightBuffer");
    materials_block_idx = glGetUniformBlockIndex(program, "MaterialBuffer");
    material_loc = glGetUniformLocation(program, "Material");
    num_lights_loc = glGetUniformLocation(program, "NumLights");
    eye_loc = glGetUniformLocation(program, "EyePosition");

    // Enable depth test
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Set initial camera position
    GLfloat x, y, z;
    x = (GLfloat)(radius*sin(azimuth*DEG2RAD)*sin(elevation*DEG2RAD));
    y = (GLfloat)(radius*cos(elevation*DEG2RAD));
    z = (GLfloat)(radius*cos(azimuth*DEG2RAD)*sin(elevation*DEG2RAD));
    eye = vec3(x, y, z);

    // Get initial time
    elTime = glfwGetTime();

    // Start loop
    while ( !glfwWindowShouldClose( window ) ) {
    	// Draw graphics
        display();
        // Update other events like input handling
        glfwPollEvents();
        // Update angle based on time for fixed rpm
        GLdouble curTime = glfwGetTime();
        if (mode >= 7) {
            GLdouble dT = (curTime - elTime);
        	/******************************************/
        	/*       INSERT (k) and (l) CODE HERE     */
        	/******************************************/
            if (tipping && !pouring){
                if (pot_theta == pour_ang){
                    pour_dir = 0;
                    tipping = false;
                    pouring = true;
                } else if(pot_theta == 0.0f){
                    coffee_y = 0;
                    pour_dir *= -1;
                }
            }

            if (!tipping && pouring){
                coffee_y += 0.001f;
                if (coffee_y == coffee_fill){
                    pouring = false;
                    tipping = true;
                }
            }

            pot_theta += pour_dir*(dT)*(ppm/60.0)*360.0;

        }
        elTime = curTime;
        // Swap buffer onto screen
        glfwSwapBuffers( window );
    }

    // Close window
    glfwTerminate();
    return 0;
}

void display( )
{
    proj_matrix = mat4().identity();
    camera_matrix = mat4().identity();

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
    proj_matrix = ortho(-8.0f*xratio, 8.0f*xratio, -8.0f*yratio, 8.0f*yratio, -8.0f, 8.0f);

    // Set camera matrix
    camera_matrix = lookat(eye, center, up);

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
    mat4 trans_matrix = mat4().identity();

    // Select shader program
    glUseProgram(program);
    // Pass projection matrix to shader
    glUniformMatrix4fv(proj_mat_loc, 1, GL_FALSE, proj_matrix);
    // Pass camera matrix to shader
    glUniformMatrix4fv(camera_mat_loc, 1, GL_FALSE, camera_matrix);

    // Bind lights
    glUniformBlockBinding(program, lights_block_idx, 0);
    glBindBufferRange(GL_UNIFORM_BUFFER, 0, LightBuffers[LightBuffer], 0, Lights.size()*sizeof(LightProperties));
    // Bind materials
    glUniformBlockBinding(program, materials_block_idx, 1);
    glBindBufferRange(GL_UNIFORM_BUFFER, 1, MaterialBuffers[MaterialBuffer], 0, Materials.size()*sizeof(MaterialProperties));
    // Set eye position
    glUniform3fv(eye_loc, 1, eye);
    // Set num lights
    glUniform1i(num_lights_loc, numLights);
    
	// Mode 0/1: Table
    draw_table();
    model_matrix = mat4().identity();
    normal_matrix = model_matrix.inverse().transpose();

	// Mode 2: Brass teapot
    if (mode == 2) {
        /******************************************/
        /*       INSERT (d) CODE HERE             */
        /******************************************/

        trans_matrix = translation(POT_X, 0.0f, POT_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(1.0f, 1.0f, 1.0f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, Brass);

        draw_object(Teapot);
    }
    // (f) Brass teapot and dough donut
    else if (mode==3)
    {
        /******************************************/
        /*       INSERT (f) CODE HERE             */
        /******************************************/

        trans_matrix = translation(POT_X, 0.0f, POT_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(1.0f, 1.0f, 1.0f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, Brass);

        draw_object(Teapot);

        trans_matrix = translation(STACK_X, 0.0f, STACK_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(0.5f, 0.5f, 0.5f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, Dough);

        draw_object(Donut);

    }
    // (g) Brass teapot and stack of three dough donuts
    else if (mode==4 || mode==5)
    {
        /******************************************/
        /*       INSERT (g) CODE HERE             */
        /******************************************/

        trans_matrix = translation(POT_X, 0.0f, POT_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(1.0f, 1.0f, 1.0f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, Brass);

        draw_object(Teapot);

        for (GLfloat i = 0.0f; i < 3.0f; ++i) {
            trans_matrix = translation(STACK_X, i*0.5f, STACK_Z);
            rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
            scale_matrix = scale(0.5f, 0.5f, 0.5f);
            model_matrix = trans_matrix*rot_matrix*scale_matrix;
            // Compute normal matrix
            normal_matrix = model_matrix.inverse().transpose();

            // Pass model matrix and normal matrix to shader
            glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
            glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
            glUniform1i(material_loc, Dough);

            draw_object(Donut);
        }
    }
    // (j) Yellow acrylic teapot, stack of three dough donuts, and red acrylic cup
    else if (mode==6)
    {
        /******************************************/
        /*       INSERT (j) CODE HERE          */
        /******************************************/
        trans_matrix = translation(POT_X, 0.0f, POT_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(1.0f, 1.0f, 1.0f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, YellowAcrylic);

        draw_object(Teapot);

        for (GLfloat i = 0.0f; i < 3.0f; ++i) {
            trans_matrix = translation(STACK_X, i*0.5f, STACK_Z);
            rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
            scale_matrix = scale(0.5f, 0.5f, 0.5f);
            model_matrix = trans_matrix*rot_matrix*scale_matrix;
            // Compute normal matrix
            normal_matrix = model_matrix.inverse().transpose();

            // Pass model matrix and normal matrix to shader
            glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
            glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
            glUniform1i(material_loc, Dough);

            draw_object(Donut);
        }

        trans_matrix = translation(CUP_X, 0.0f, CUP_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(0.25f, 1.0f, 0.25f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, RedAcrylic);
        glDepthMask(GL_FALSE);
        draw_object(Cylinder);
        glDepthMask(GL_TRUE);
    }
    // (k) Animated yellow acrylic teapot, stack of three dough donuts, and red acrylic cup
    else if (mode==7)
    {
        /******************************************/
        /*       INSERT (k) CODE HERE          */
        /******************************************/
        trans_matrix = translation(POT_X, 1.3f, POT_Z);
        rot_matrix = rotation(pot_theta, 0.0f, 0.0f, 1.0f);
        scale_matrix = scale(1.0f, 1.0f, 1.0f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, YellowAcrylic);

        draw_object(Teapot);

        for (GLfloat i = 0.0f; i < 3.0f; ++i) {
            trans_matrix = translation(STACK_X, i*0.5f, STACK_Z);
            rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
            scale_matrix = scale(0.5f, 0.5f, 0.5f);
            model_matrix = trans_matrix*rot_matrix*scale_matrix;
            // Compute normal matrix
            normal_matrix = model_matrix.inverse().transpose();

            // Pass model matrix and normal matrix to shader
            glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
            glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
            glUniform1i(material_loc, Dough);

            draw_object(Donut);
        }

        trans_matrix = translation(CUP_X, 0.0f, CUP_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(0.25f, 1.0f, 0.25f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, RedAcrylic);
        glDepthMask(GL_FALSE);
        draw_object(Cylinder);
        glDepthMask(GL_TRUE);

    }
    // (l) Animated yellow acrylic teapot, stack of three dough donuts, and red acrylic cup
    //     filling with coffee
    else if (mode==8)
    {
        /******************************************/
        /*       INSERT (l) CODE HERE          */
        /******************************************/
        trans_matrix = translation(POT_X, 1.3f, POT_Z);
        rot_matrix = rotation(pot_theta, 0.0f, 0.0f, 1.0f);
        scale_matrix = scale(1.0f, 1.0f, 1.0f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, YellowAcrylic);

        draw_object(Teapot);

        for (GLfloat i = 0.0f; i < 3.0f; ++i) {
            trans_matrix = translation(STACK_X, i*0.5f, STACK_Z);
            rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
            scale_matrix = scale(0.5f, 0.5f, 0.5f);
            model_matrix = trans_matrix*rot_matrix*scale_matrix;
            // Compute normal matrix
            normal_matrix = model_matrix.inverse().transpose();

            // Pass model matrix and normal matrix to shader
            glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
            glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
            glUniform1i(material_loc, Dough);

            draw_object(Donut);
        }

        trans_matrix = translation(CUP_X, 0.0f, CUP_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(0.25f, 1.0f, 0.25f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, RedAcrylic);
        glDepthMask(GL_FALSE);
        draw_object(Cylinder);
        glDepthMask(GL_TRUE);

        trans_matrix = translation(CUP_X, coffee_y, CUP_Z);
        rot_matrix = rotation(0.0f, 0.0f, 1.0f, 0.0f);
        scale_matrix = scale(0.225f, 1.0f, 0.225f);
        model_matrix = trans_matrix*rot_matrix*scale_matrix;
        // Compute normal matrix
        normal_matrix = model_matrix.inverse().transpose();

        // Pass model matrix and normal matrix to shader
        glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
        glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
        glUniform1i(material_loc, Coffee);
        glDepthMask(GL_FALSE);
        draw_object(Cylinder);
        glDepthMask(GL_TRUE);
    }

}

void build_lights( ) {
    Lights.clear();
    if (mode > 0) {
        /******************************************/
        /*       INSERT (b) CODE HERE             */
        /******************************************/
        LightProperties whitePointLight = {POINT, //type
                                           {0.0f, 0.0f, 0.0f}, //pad3
                                           vec4(0.4f, 0.4f, 0.4f, 1.0f), //ambient
                                           vec4(1.0f, 1.0f, 1.0f, 1.0f), //diffuse
                                           vec4(1.0f, 1.0f, 1.0f, 0.0f), //specular
                                           vec4(whiteLightPos),  //position
                                           vec4(0.0f, -1.0f, 0.0f, 1.0f), //direction
                                           10.0f,   //cutoff
                                           1.0f,  //exponent
                                           {0.0f, 0.0f}  //pad2
        };
        
        
        Lights.push_back(whitePointLight);
    }
    if (mode > 4) {
        /******************************************/
        /*       INSERT (h) CODE HERE             */
        /******************************************/
        LightProperties redSpotLight = {SPOT, //type
                                          {0.0f, 0.0f, 0.0f}, //pad
                                          vec4(0.0f, 0.0f, 0.0f, 1.0f), //ambient
                                          vec4(1.0f, 0.0f, 0.0f, 1.0f), //diffuse
                                          vec4(1.0f, 1.0f, 1.0f, 1.0f), //specular
                                          vec4(STACK_X, 4.0f, STACK_Z, 1.0f),  //position
                                          vec4(0.0f, -1.0f, 0.0f, 0.0f), //direction
                                          30.0f,   //cutoff
                                          30.0f,  //exponent
                                          {0.0f, 0.0f}  //pad2
        };

        Lights.push_back(redSpotLight);
    }

    numLights = Lights.size();

    // Create uniform buffer for lights
    if (glIsBuffer(LightBuffers[LightBuffer])) {
        glDeleteBuffers(NumLightBuffers, LightBuffers);
    }
    glGenBuffers(NumLightBuffers, LightBuffers);
    glBindBuffer(GL_UNIFORM_BUFFER, LightBuffers[LightBuffer]);
    glBufferData(GL_UNIFORM_BUFFER, Lights.size()*sizeof(LightProperties), Lights.data(), GL_STATIC_DRAW);
}

void build_materials( ) {
    Materials.clear();
    // Create grey plastic material
    MaterialProperties greyPlastic = {vec4(0.1f, 0.1f, 0.1f, 1.0f), //ambient
                                     vec4(0.6f, 0.6f, 0.6f, 1.0f), //diffuse
                                     vec4(0.8f, 0.8f, 0.8f, 1.0f), //specular
                                     10.0f, //shininess
                                     {0.0f, 0.0f, 0.0f}  //pad
    };
    Materials.push_back(greyPlastic);

    if (mode >= 2) {
        /******************************************/
        /*       INSERT (c) CODE HERE             */
        /******************************************/
        MaterialProperties brass = {vec4(0.33f, 0.22f, 0.03f, 1.0f), //ambient
                                    vec4(0.78f, 0.57f, 0.11f, 1.0f), //diffuse
                                    vec4(0.99f, 0.91f, 0.81f, 1.0f), //specular
                                    27.8f, //shininess
                                    {0.0f, 0.0f, 0.0f}  //pad
        };
        
        
        Materials.push_back(brass);
    }

    if (mode >= 3) {
        /******************************************/
        /*       INSERT (e) CODE HERE             */
        /******************************************/
        MaterialProperties dough = {vec4(0.3f, 0.0f, 0.0f, 1.0f), //ambient
                                    vec4(0.97f, 0.89f, 0.77f, 1.0f), //diffuse
                                    vec4(0.8f, 0.6f, 0.6f, 1.0f), //specular
                                    32.0f, //shininess
                                    {0.0f, 0.0f, 0.0f}  //pad
        };
        
        
        Materials.push_back(dough);
    }

    if (mode >= 6) {
        /******************************************/
        /*       INSERT (i) CODE HERE             */
        /******************************************/
        MaterialProperties yellowAcrylic = {vec4(0.3f, 0.0f, 0.0f, 0.4f), //ambient
                                            vec4(1.0f, 1.0f, 0.0f, 0.4f), //diffuse
                                            vec4(0.8f, 0.6f, 0.6f, 0.4f), //specular
                                            32.0f, //shininess
                                            {0.0f, 0.0f, 0.0f}  //pad
        };

        MaterialProperties redAcrylic = {vec4(0.3f, 0.0f, 0.0f, 0.6f), //ambient
                                         vec4(1.0f, 0.0f, 0.0f, 0.6f), //diffuse
                                         vec4(0.8f, 0.6f, 0.6f, 0.6f), //specular
                                         32.0f, //shininess
                                         {0.0f, 0.0f, 0.0f}  //pad
        };

        Materials.push_back(yellowAcrylic);
        Materials.push_back(redAcrylic);
    }

    if (mode >= 8) {
        /******************************************/
        /*       INSERT (l) CODE HERE             */
        /******************************************/
        MaterialProperties coffee = {vec4(0.3f, 0.0f, 0.0f, 0.5f), //ambient
                                     vec4(0.1f, 0.1f, 0.1f, 0.8f), //diffuse
                                     vec4(0.8f, 0.6f, 0.6f, 0.5f), //specular
                                     32.0f, //shininess
                                     {0.0f, 0.0f, 0.0f}  //pad
        };
        
        
        Materials.push_back(coffee);
    }

    // Create uniform buffer for materials
    // Create uniform buffer for lights
    if (glIsBuffer(MaterialBuffers[MaterialBuffer])) {
        glDeleteBuffers(NumMaterialBuffers, MaterialBuffers);
    }
    glGenBuffers(NumMaterialBuffers, MaterialBuffers);
    glBindBuffer(GL_UNIFORM_BUFFER, MaterialBuffers[MaterialBuffer]);
    glBufferData(GL_UNIFORM_BUFFER, Materials.size()*sizeof(MaterialProperties), Materials.data(), GL_STATIC_DRAW);
}

#include "examfunc.cpp"