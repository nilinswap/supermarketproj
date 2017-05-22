#include <Python.h>

int
main(int argc, char *argv[])
{
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pArg, *pResult;
    int i;

    Py_Initialize();
    pName = PyString_FromString("reverse.py");
    /* Error checking of pName left out as exercise */

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, "rnum");
        /* pFunc is a new reference */

        if (pFunc) {
            pArgs = PyTuple_New(0);
            pArg = Py_BuildValue("i", 6);
            /* pArg reference stolen here: */
            PyTuple_SetItem(pArgs, 0, pArg);
            pResult = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pResult != NULL) {
                printf("Result of call: %s\n", PyString_AsString(pResult));
                Py_DECREF(pResult);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function");
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load module");
        return 1;
    }
    Py_Finalize();
    return 0;
}