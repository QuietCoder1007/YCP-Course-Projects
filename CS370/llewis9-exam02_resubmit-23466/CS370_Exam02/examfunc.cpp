/******************************************/
/*!!!!!DO NOT MODIFY PAST THIS POINT!!!!!!*/
/******************************************/
void build_geometry( )
{
    // Generate vertex arrays and buffers
    glGenVertexArrays(NumVAOs, VAOs);

    load_object(Cube);

    load_object(Donut);

    load_object(Teapot);

    load_object(Cylinder);

}

void draw_table(){
    // Draw cube
    mat4 trans_matrix = translate(0.0f, -0.1f, 0.0f);
    mat4 scale_matrix = scale(TABLE_SIZE, 0.1f, TABLE_SIZE);
    model_matrix = trans_matrix*scale_matrix;
    // Compute normal matrix
    normal_matrix = model_matrix.inverse().transpose();
    // Pass model matrix, normal matrix, and material index to shader
    glUniformMatrix4fv(model_mat_loc, 1, GL_FALSE, model_matrix);
    glUniformMatrix4fv(norm_mat_loc, 1, GL_FALSE, normal_matrix);
    glUniform1i(material_loc, GreyPlastic);
    draw_object(Cube);

}

void draw_object(GLuint obj){
    glBindVertexArray(VAOs[obj]);
    glBindBuffer(GL_ARRAY_BUFFER, ObjBuffers[obj][PosBuffer]);
    glVertexAttribPointer(vPos, posCoords, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(vPos);
    glBindBuffer(GL_ARRAY_BUFFER, ObjBuffers[obj][NormBuffer]);
    glVertexAttribPointer(vNorm, normCoords, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(vNorm);
    glDrawArrays(GL_TRIANGLES, 0, numVertices[obj]);

}

void load_object(GLuint obj) {
    vector<vec4> vertices;
    vector<vec2> uvCoords;
    vector<vec3> normals;

    loadOBJ(objFiles[obj], vertices, uvCoords, normals);
    numVertices[obj] = vertices.size();
    // Create and load object buffers
    glGenBuffers(NumObjBuffers, ObjBuffers[obj]);
    glBindVertexArray(VAOs[obj]);
    glBindBuffer(GL_ARRAY_BUFFER, ObjBuffers[obj][PosBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*posCoords*numVertices[obj], vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, ObjBuffers[obj][NormBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*normCoords*numVertices[obj], normals.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    // Esc closes window
    if (key == GLFW_KEY_ESCAPE) {
        glfwSetWindowShouldClose(window, true);
    }

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
        mode++;
        if (mode > NUM_MODES)
        {
            mode = 0;
            tipping = false;
            pouring = false;
        }
        if (mode == 0 || mode == 1 || mode == 5) {
            build_lights();
        }
        if (mode == 2 || mode == 3 || mode == 6 || mode == 8) {
            build_materials();
        }
        if (mode == 7) {
            tipping = true;
        }

    }

    // Adjust azimuth
    if (key == GLFW_KEY_A) {
        azimuth += daz;
        if (azimuth > 360.0) {
            azimuth -= 360.0;
        }
    } else if (key == GLFW_KEY_D) {
        azimuth -= daz;
        if (azimuth < 0.0)
        {
            azimuth += 360.0;
        }
    }

    // Adjust elevation angle
    if (key == GLFW_KEY_W)
    {
        elevation += del;
        if (elevation > 180.0)
        {
            elevation = 179.0;
        }
    }
    else if (key == GLFW_KEY_S)
    {
        elevation -= del;
        if (elevation < 0.0)
        {
            elevation = 1.0;
        }
    }

    // Compute updated camera position
    GLfloat x, y, z;
    x = (GLfloat)(radius*sin(azimuth*DEG2RAD)*sin(elevation*DEG2RAD));
    y = (GLfloat)(radius*cos(elevation*DEG2RAD));
    z = (GLfloat)(radius*cos(azimuth*DEG2RAD)*sin(elevation*DEG2RAD));
    eye = vec3(x,y,z);
}

void mouse_callback(GLFWwindow *window, int button, int action, int mods){

}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);

    // Store new window sizes in global variables
    ww = width;
    hh = height;
}

