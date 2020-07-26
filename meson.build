project('matrixcode', 'cpp', default_options : ['cpp_std=c++17'], version : '0.1')
qt5 = import('qt5')
qt5_dep = dependency('qt5', modules: ['Core', 'Gui', 'Widgets', 'OpenGL'])
gl_dep = dependency('GL')
moc_files = qt5.preprocess(moc_headers : 'matrixcode.hpp',
                                       dependencies : [qt5_dep, gl_dep])


executable('matrixcode','main.cpp', 'matrixcode.cpp', moc_files,dependencies : [qt5_dep, gl_dep ])
