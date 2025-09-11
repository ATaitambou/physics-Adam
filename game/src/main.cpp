#include "raylib.h"
#include "raymath.h"

int main()
{

    
    InitWindow(800, 800, "Physics-1");

	Vector2 circleposition_1 = { 400.0f, 400.0f }; // circle 1 position
	Vector2 circleposition_2 = { 400.0f, 400.0f }; // circle 2 position
	float circleradius_1 = 25.0f; // circle radius
	Color circlecolor_1 = PURPLE;

	while (!WindowShouldClose()) // Detect window close button or ESC key
    {
		float t = GetTime();
		float dt = GetFrameTime();

		circleposition_1.x = 400.0f + 150.0f * sin(t); // moving left and right within 150 units forever
		circleposition_2.y += 10.0f * dt; // moving down at 10 units per second


        BeginDrawing();
            ClearBackground(DARKGREEN);
            DrawText("Adam Taitambou 101399640", 10, 10, 20, BLACK);
			DrawCircleV(circleposition_1, circleradius_1, circlecolor_1);
			DrawCircleV(circleposition_2, circleradius_1, RED); 
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
