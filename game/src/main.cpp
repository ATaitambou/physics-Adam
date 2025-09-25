#include "raylib.h"
#include "raymath.h"

int main()
{

    
	InitWindow(800, 800, "Physics-Adam"); // Window size and title changes

	
	
	
	Rectangle platform;
	platform.x = 0.0f;
	platform.y = 600.0f;
	platform.width = 100.0f;
	platform.height = 20.0f;

	Rectangle ground;
	ground.x = 0.0f;
	ground.y = 780.0f;
	ground.width = 800.0f;
	ground.height = 20.0f;

	class Bird 
	{
	public:
		float radius = 10.0f;
		float launchSpeed = 150.0f;
		float launchAngle = 90.0f;

		Vector2 birdposition;
		Vector2 launchposition;
		Vector2 launchVelocity;
		Vector2 birdvelocity;
		Vector2 birdacceleration = { 0.0f, 9.81f }; // Gravity acceleration
		Vector2 futureLaunchVelocity;

		Bird(Rectangle platform)
		{

			// Birds Starting Position and Velocity
			birdposition.x = platform.x + platform.width - radius; // Launch at right end of platform doing the math for me
			birdposition.y = platform.y - (platform.height - radius); // Launch at top of platform doing the math for me

			launchposition = birdposition; // Store start position for reset
			
			// Launch velocity
			launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed; // Calculate launch velocity from angle and speed
			futureLaunchVelocity = launchVelocity; // For drawing the launch angle line
			birdvelocity = launchVelocity; // Initial velocity

			birdacceleration = { 0.0f, 9.81f }; // Gravity acceleration
			bool launched = false;
		}
		// Used a method to reset position and velocity when space is pressed

		void launch()
		{
			birdposition = launchposition;// 1. Set bird position to launch position 
			birdvelocity = launchVelocity;// 2. Set bird velocity based on the launch angle and launchspeed see intial launchvelocity asssignemnt 
		}

	};

	

	Bird bird(platform);

	while (!WindowShouldClose()) // Detect window close button or ESC key
    {


		
		float t = GetTime();  // Get time in seconds since InitWindow()
		float dt = GetFrameTime(); // Get time in seconds for last frame drawn (delta time)


		/*launchVelocity = launchVelocity + birdacceleration * dt;*/

		//When key is pressed lab 2
		if(IsKeyPressed(KEY_SPACE)) // Reset position and velocity when space is pressed
		{

			bird.launch(); // Using the launch function from the bird class to reset position and velocity
			//bird.birdposition = bird.launchposition;// 1. Set bird position to launch position 
			//bird.birdvelocity = bird.launchVelocity;// 2. Set bird velocity based on the launch angle and launchspeed see intial launchvelocity asssignemnt 
			
			
			
		}
		if (IsKeyDown(KEY_DOWN)) // Increasing launch angle
		{
			bird.launchAngle += 90.0f * DEG2RAD * dt;
			bird.launchVelocity = Vector2Rotate(Vector2UnitX, bird.launchAngle) * bird.launchSpeed;// Tried leaving as is but it woildnt be illistrated so leave it in 
			bird.birdvelocity = bird.launchVelocity;
			
		}
		if (IsKeyDown(KEY_UP)) // Decreasing launch angle
		{
			bird.launchAngle -= 90.0f * DEG2RAD * dt;
			bird.launchVelocity = Vector2Rotate(Vector2UnitX, bird.launchAngle) * bird.launchSpeed;
			bird.birdvelocity = bird.launchVelocity;
		}
		if (IsKeyDown(KEY_RIGHT)) // Increasing launch speed
		{
			bird.launchSpeed += 90.0f * dt;
			///*launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed;*/
			bird.birdvelocity = bird.launchVelocity;
			
		}
		if(IsKeyDown(KEY_LEFT)){  // Decreasing launch speed
			bird.launchSpeed -= 90.0f * dt ;
			bird.launchVelocity = Vector2Rotate(Vector2UnitX, bird.launchAngle) * bird.launchSpeed;
			bird.birdvelocity = bird.launchVelocity;
		}
		if(IsKeyDown(KEY_G)) // Increasing gravity
		{
			bird.birdacceleration.y += 9.81f * dt;
		}
		if(IsKeyDown(KEY_H)) // Decreasing gravity
		{
			bird.birdacceleration.y -= 9.81f * dt;
		}
	
		if(IsKeyDown(KEY_ESCAPE))
		{
			CloseWindow();
		}
		
		bird.futureLaunchVelocity = Vector2Rotate(Vector2UnitX, bird.launchAngle) * bird.launchSpeed; // For drawing the launch angle line
		
		bird.birdvelocity += bird.birdacceleration * dt;// Change velocity when space is pressed
		bird.birdposition += bird.birdvelocity * dt; // Change position based on velocity

        BeginDrawing();
            ClearBackground(WHITE); // Background changes

			//Where our bird is drawn and the platform and ground
			DrawCircleV(bird.birdposition, bird.radius, RED);
			DrawCircleV(bird.launchposition, bird.radius,DARKBLUE);
			DrawRectangleRec(platform, BEIGE);
			DrawRectangleRec(ground, BLUE);

			//Displaying the launch angle line
			DrawLineV(bird.launchposition, bird.launchposition + bird.futureLaunchVelocity,RED);

			// Texts That are added to the screen
			DrawText("Adam Taitambou 101399640", 10, 10, 20, BLACK);
			DrawText(TextFormat("Launch Position: %f %f ",bird.launchposition.x, bird.launchposition.y),10,30,20, BLACK);
			DrawText(TextFormat("Launch Angle: %f ", bird.launchAngle), 10, 50, 20, BLACK);
			DrawText(TextFormat("Launch Speed: %f ", bird.launchSpeed), 10, 70, 20, BLACK);
			DrawText(TextFormat("Gravity: %f ", bird.birdacceleration), 10, 90, 20, BLACK);
			
        EndDrawing();
    }

    CloseWindow();
    return 0;
}



// ontop of while loop
	//float radius = 10.0f;
	//Vector2 birdposition;
	//birdposition.x = platform.x + platform.width - radius; // Launch at right end of platform doing the math for me
	//birdposition.y = platform.y - (platform.height - radius); // Launch at top of platform doing the math for me

	//float launchSpeed = 150.0f;
	//float launchAngle = 45.0f;

	//// Reassign launchvelocity like when space is pressed part 1
	//Vector2 launchposition = birdposition; // Store start position for reset
	//Vector2 launchVelocity = Vector2Rotate(Vector2UnitX, launchAngle) * launchSpeed; // Calculate launch velocity from angle and speed
	//Vector2 futureLaunchVelocity = launchVelocity; // For drawing the launch angle line


	//Vector2 birdvelocity = launchVelocity; // Initial velocity
	//Vector2 birdacceleration = { 0.0f, 9.81f }; // Gravity acceleration