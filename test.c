#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAX_VERTICES 1000
#define MAX_FACES 1000

typedef struct {
    float x, y, z;
} Vertex;

typedef struct {
    int vIdx[3];
} Face;

Vertex vertices[MAX_VERTICES];
Face faces[MAX_FACES];
int vertexCount = 0, faceCount = 0;

float angleX = 0.0f;
float angleY = 0.0f;
float zoom = 1.0f;
int lastMouseX, lastMouseY;
bool mouseDown = false;

void parseObjFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(1);
    }

    char line[128];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "v ", 2) == 0) {
            if (vertexCount >= MAX_VERTICES) {
                fprintf(stderr, "Too many vertices\n");
                exit(1);
            }
            Vertex vertex;
            sscanf(line + 2, "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
            vertices[vertexCount++] = vertex;
        } else if (strncmp(line, "f ", 2) == 0) {
            if (faceCount >= MAX_FACES) {
                fprintf(stderr, "Too many faces\n");
                exit(1);
            }
            Face face;
            int matches = sscanf(line + 2, "%d %d %d",
                                 &face.vIdx[0], &face.vIdx[1], &face.vIdx[2]);
            if (matches != 3) {
                fprintf(stderr, "Error reading face data\n");
                exit(1);
            }
            for (int i = 0; i < 3; i++) {
                if (face.vIdx[i] < 1 || face.vIdx[i] > vertexCount) {
                    fprintf(stderr, "Invalid vertex index %d in face definition\n", face.vIdx[i]);
                    exit(1);
                }
                face.vIdx[i]--; // Convert 1-based index to 0-based index
            }
            faces[faceCount++] = face;
        }
    }

    fclose(file);
}

void handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouseDown = true;
                    lastMouseX = event.button.x;
                    lastMouseY = event.button.y;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    mouseDown = false;
                }
                break;
            case SDL_MOUSEMOTION:
                if (mouseDown) {
                    int deltaX = event.motion.x - lastMouseX;
                    int deltaY = event.motion.y - lastMouseY;
                    angleY += deltaX * 0.5f;
                    angleX += deltaY * 0.5f;
                    lastMouseX = event.motion.x;
                    lastMouseY = event.motion.y;
                }
                break;
            case SDL_MOUSEWHEEL:
                zoom += event.wheel.y * 0.1f;
                if (zoom < 0.1f) zoom = 0.1f;
                break;
            default:
                break;
        }
    }
}

void drawModel() {
    glBegin(GL_TRIANGLES);

    for (int i = 0; i < faceCount; i++) {
        for (int j = 0; j < 3; j++) {
            int vIdx = faces[i].vIdx[j];
            glVertex3f(vertices[vIdx].x, vertices[vIdx].y, vertices[vIdx].z);
        }
    }

    glEnd();
}

void display(SDL_Window* window) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glScalef(zoom, zoom, zoom);

    drawModel();

    SDL_GL_SwapWindow(window);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <path_to_obj_file>\n", argv[0]);
        return 1;
    }

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL2/OpenGL 3D Model Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)SCREEN_WIDTH / (GLfloat)SCREEN_HEIGHT, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);

    parseObjFile(argv[1]);

    bool quit = false;
    while (!quit) {
        handleEvents();
        display(window);
        SDL_Delay(10);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
