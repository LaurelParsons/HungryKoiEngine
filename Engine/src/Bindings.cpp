#include <pybind11/pybind11.h>
#include <SDL3/SDL.h>
#include "Application.hpp"
#include "Scene.hpp"

namespace py = pybind11;

/**
* Module containing the python bindings for the engine.
*
* Contains bindings to the application class, allowing external code to start and set up a scene.
*/

PYBIND11_MODULE(mygameengine, m) {
	m.doc() = "Engine library";

	py::class_<Application>(m, "Application")
		.def(py::init<int, int>())
		.def("StartScene", &Application::StartScene)
		.def("AddPlayer", &Application::AddPlayerToScene)
		.def("AddEnemy", &Application::AddEnemyToScene)
		.def("Loop", &Application::Loop);
}
