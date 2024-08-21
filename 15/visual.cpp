#include <cmath>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
// #include <chrono>
#include <raylib.h>
#include <sys/time.h>

using std::cout;
using std::endl;
using std::sqrt;
using std::string;
using std::to_string;
using std::vector;

// using namespace std::chrono;

#define ROWS 21
#define COLS 21

// bool lattice[ROWS][COLS];

// vector<vector<unsigned long int>> path_counts;

unsigned long int path_counts[ROWS][COLS];

RenderTexture target;
Camera3D camera3d = {0};
Camera2D camera2d = {0};

unsigned long int traverse_lattice(int i, int j) {
  // usleep(500000);
  if (i == ROWS - 1 && j == COLS - 1) {
    // cout << "traverse_lattice(" << i << ", " << j << "): " << 1 << endl;
    path_counts[i][j] = 1;
    return 1;
  } else if (j == COLS - 1) {
    unsigned long int v = path_counts[i][j];
    if (v == 0) {
      v = traverse_lattice(i + 1, j);
      path_counts[i][j] = v;
    }
    return v;
  } else if (i == ROWS - 1) {
    unsigned long int v = path_counts[i][j];
    if (v == 0) {
      v = traverse_lattice(i, j + 1);
      path_counts[i][j] = v;
    }
    return v;
  }
  unsigned long int v = path_counts[i][j];
  if (v == 0) {
    v = traverse_lattice(i, j + 1) + traverse_lattice(i + 1, j);
    path_counts[i][j] = v;
  }

  // on every call to traverse_lattice, we will need to re-paint the window
  // as each call bubbles up, the bottom most call gets drawn first

  BeginDrawing();
  BeginMode2D(camera2d);
  BeginTextureMode(target);
  // BeginMode3D(camera3d);
  ClearBackground(RAYWHITE);

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      const int v = (int)path_counts[i][j];
      const unsigned char r = v % 255;
      const unsigned char g = v % 255;
      const unsigned char b = v % 255;
      Color c = {r, g, b, 255};
      DrawRectangle(j * 40, i * 40, 40, 40, c);
    }
  }

  // DrawGrid(ROWS, 1.0f);
  //  DrawCube((Vector3){0.5f, 0.5f, 0.5f}, 1.0f, 1.0f, 1.0f, RED);
  //  DrawCube((Vector3){COLS - 0.5f, ROWS - 0.5f, 0.5f}, 1.0f, 1.0f, 1.0f,
  //  BLUE); EndMode3D();
  EndMode2D();
  EndTextureMode();
  DrawTexture(target.texture, 0, 0, WHITE);
  EndDrawing();

  return v;
}

bool is_prime(unsigned long int n);

int main() {

  InitWindow(1280, 960, "Visual");
  SetTargetFPS(60);
  target = LoadRenderTexture(1280, 960);
  // cout << "evildojo " << endl;

  while (!WindowShouldClose()) {

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        path_counts[i][j] = 0;
      }
    }

    BeginDrawing();
    BeginMode2D(camera2d);
    BeginTextureMode(target);
    ClearBackground(RAYWHITE);

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        const int v = (int)path_counts[i][j];
        const unsigned char r = v % 255;
        const unsigned char g = v % 255;
        const unsigned char b = v % 255;
        Color c = {r, g, b, 255};
        DrawRectangle(j * 40, i * 40, 40, 40, c);
      }
    }

    EndMode2D();
    EndTextureMode();
    DrawTexture(target.texture, 0, 0, WHITE);
    EndDrawing();

    // get input
    if (IsKeyPressed(KEY_ENTER)) {
      cout << "Enter key pressed" << endl;

      unsigned long int paths = traverse_lattice(0, 0);
    }
  }

  // struct timeval tp;
  // gettimeofday(&tp, NULL);
  // long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;

  // gettimeofday(&tp, NULL);
  // long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

  // long int diff = ms2 - ms;

  // cout << paths << endl;
  // cout << "Program took " << diff << "ms to run" << endl;

  UnloadRenderTexture(target);
  CloseWindow();

  return 0;
}

bool is_prime(unsigned long int n) {
  if (n < 2) {
    return false;
  }
  // for (int i = 2; i < n; i++) {
  // cout << "sqrt(" << n << "): " << sqrt(n) << endl;
  for (unsigned long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
