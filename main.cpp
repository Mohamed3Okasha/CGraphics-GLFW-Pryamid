#include <GLFW/glfw3.h>
#include <iostream>

//int rotate_y = 0;
int rotate_x = 0;
float s = 0.7f;

void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		rotate_x += 5;

	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
		rotate_x -= 5;

	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
		s -= .1;

	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
		s += .1;

}
void Sym_Pyramid() {

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(0.0f, 1.f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	
	glColor3f(0.5f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3f(0.0f, 1.0f, 0.5f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
}
int main(int argc, char const *argv[]) {
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(800, 600, "Rotating Cube", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glEnable(GL_DEPTH_TEST);

	// render loop
	// -----------
	while (!glfwWindowShouldClose(window)) {
		glfwSetKeyCallback(window, keyboard_callback);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();

		glRotatef((float)rotate_x, 1.0, 0.0, 0.0);
		//glRotate((float)rotate_y, 0.0, 1.0, 0.0);
		glScalef(s, s, s);

		Sym_Pyramid();
		
		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}

