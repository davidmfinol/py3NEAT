#include <Python.h>
#include "neuron.hpp"
#include "synapse.hpp"

static PyModuleDef ifnn_cppmodule = {
    PyModuleDef_HEAD_INIT,
    "ifnn_cpp",
    "ifnn_cpp module description",
    -1,
    NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC PyInit_ifnn_cpp(void)
{	
	PyObject* module;
	module = PyModule_Create(&ifnn_cppmodule);
    if (module == NULL)
        return NULL;
	
	/* Neuron */
	
	NeuronType.tp_new = PyType_GenericNew;
	if (PyType_Ready(&NeuronType) < 0)
		return NULL;
	
	Py_INCREF(&NeuronType);
	PyModule_AddObject(module, "Neuron", reinterpret_cast<PyObject*>(&NeuronType));
	
	/* Synapse */
		
	SynapseType.tp_new = PyType_GenericNew;
	if (PyType_Ready(&SynapseType) < 0)
		return NULL;
		
	Py_INCREF(&SynapseType);
	PyModule_AddObject(module, "Synapse", reinterpret_cast<PyObject*>(&SynapseType));
	
	return module;
}
