#include<iostream>
#define GLEW_STATIC
#include<GL/glew.h>
//glew需要有限导入
#include<GLFW/glfw3.h>
using namespace std;
static unsigned int CompileShader(unsigned int type, const string* cource) {
	//根据传入的着色器类型和源码编译出相应的着色器
	unsigned int id = glCreateShader(type);
	const char* src = cource->c_str(); 
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);
	//错误处理
	return id;
}
static unsigned int CreateShader(const string* vertexShader,const string* fragmentShader) {
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	//着色器编译链接完成后可以删除着色器，
	glDeleteShader(vs);
	glDeleteShader(fs);

	//最终返回程序的id
	return program;
} 
//编写两种着色器的源代码。
string vertexShader =	
	"#version 330 core\n"
	"layout(location = 0) in vec4 position;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = position;\n"
	"}\n";
string fragmentShader =
	"#version 330 core\n"
	"layout(location = 0) out vec4 color;\n"
	"void main()\n"
	"{\n"
	"	color = vec4(1.0,0.0,0.0,1.0);\n"
	"}\n";
int main() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(1920, 1080, "first window", NULL, NULL);
	//GLFWwindow* window = glfwCreateWindow(640, 480, "我的标题", glfwGetPrimaryMonitor(), NULL);
	glfwMakeContextCurrent(window);
	glewInit();//glew初始化需要在上下文定义之后
	cout << glGetString(GL_VERSION) << endl;
	float position[6] = {
		-0.5f,-0.5f,
		0.5f,-0.5f,
		0.0f,0.5f
	};
	unsigned int buffer;
	glGenBuffers(1,&buffer);//创建缓冲区的标识Id
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER,6*sizeof(buffer), position,GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	
	unsigned int shader = CreateShader(&vertexShader, &fragmentShader);
	glUseProgram(shader);
	while (!glfwWindowShouldClose(window))
	{  
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	//回收内存
	glDeleteProgram(shader);
	return 0;
}