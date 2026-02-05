#include <Python.h>
#include <stdio.h>
#include "python_embed.h"

static int python_ready = 0;

void python_init(void) {
    if (python_ready) return;

    Py_Initialize();

    PyRun_SimpleString(
        "import sys\n"
        "sys.path.append('.')\n"
    );

    python_ready = 1;
}

void python_run_banner(void) {
    if (!python_ready) {
        fprintf(stderr, "[!] Python not initialized\n");
        return;
    }

    PyObject *module = PyImport_ImportModule("banner");
    if (!module) {
        PyErr_Print();
        return;
    }

    PyObject *func = PyObject_GetAttrString(module, "py_initialized");
    if (!func || !PyCallable_Check(func)) {
        PyErr_Print();
        Py_XDECREF(func);
        Py_DECREF(module);
        return;
    }

    PyObject *result = PyObject_CallObject(func, NULL);
    if (!result) {
        PyErr_Print();
    } else {
        Py_DECREF(result);
    }

    Py_DECREF(func);
    Py_DECREF(module);
}

void python_shutdown(void) {
    if (!python_ready) return;

    Py_Finalize();
    python_ready = 0;
}
	
