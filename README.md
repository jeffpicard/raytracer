raytracer
=========
Raytracer in C++
Based on Caltech course CS11
http://courses.cms.caltech.edu/cs11/material/advcpp/


Required libraries:
boost  'sudo apt-get install libboost-all-dev'
Google C++ Testing Framework (for optional unit tests)
https://code.google.com/p/googletest/


To run:
For default scene description from lab4
'make image'

For a custom scene specified in scene_desc.txt
'make'
'./rt < scene_desc.txt | pnmtopng > outputFile.png' 


Google Unit tests:
make tests
./test_Vector3F
./test_Color
./test_Scene


