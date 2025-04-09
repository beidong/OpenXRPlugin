#ifndef OPENXRPLUGIN_GLOBAL_H
#define OPENXRPLUGIN_GLOBAL_H


#if defined(OPENXRPLUGIN_LIBRARY)
#  define OPENXRPLUGIN_EXPORT __declspec(dllexport)
#else
#  define OPENXRPLUGIN_EXPORT __declspec(dllimport)
#endif

#endif // OPENXRPLUGIN_GLOBAL_H
