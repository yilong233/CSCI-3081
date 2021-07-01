### Feedback for Lab 13

Run on April 28, 10:02:05 AM.

+ :x:  Run git ls-remote to check for existence of specific branch- Branch devel not found

+ :leftwards_arrow_with_hook:  Checkout devel branch. (Test not run because of an earlier failing test)


#### Necessary Files and Structure

+ :leftwards_arrow_with_hook:  Check that directory "project" exists. (Test not run because of an earlier failing test)

+ :leftwards_arrow_with_hook:  Check that directory "project/bin" exists. (Test not run because of an earlier failing test)

+ :leftwards_arrow_with_hook:  Check that directory "project/docs" exists. (Test not run because of an earlier failing test)

+ :leftwards_arrow_with_hook:  Check that directory "project/src" exists. (Test not run because of an earlier failing test)

+ :leftwards_arrow_with_hook:  Check that directory "project/tests" exists. (Test not run because of an earlier failing test)

+ :leftwards_arrow_with_hook:  Check that directory "project/web" exists. (Test not run because of an earlier failing test)

+ :leftwards_arrow_with_hook:  Check that file "project/Makefile" exists. (Test not run because of an earlier failing test)

---


#### Compile Simulation and Tests

+ :heavy_check_mark:  Change into directory "project".

+ :heavy_check_mark:  Copy directory "Files for correct version".



+ :heavy_check_mark:  Check that make  compiles.



+ :x:  Check that make test compiles.

    Make compile fails with errors:.
<pre>cd tests; make
make[1]: Entering directory '/project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31/project/tests'
mkdir -p /project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/test
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -std=c++11 -fPIC  -Wl,-rpath,/project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/lib -I/project/grades/Spring-2021/csci3081/dependencies/include -I../src -I../include -I. -I.. -L/project/grades/Spring-2021/csci3081/dependencies/lib -L/project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/lib *.cc -lgtest_main -lgtest -lgmock -pthread -lcsci3081proj -lEntityProject -lCppWebServer -lwebsockets -lssl -lcrypto -lz -o /project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/test/csci3081tests
/usr/bin/ld: /tmp/ccCpFKee.o: in function `csci3081::DroneTest::DroneTest()':
drone_test.cc:(.text._ZN8csci30819DroneTestC2Ev[_ZN8csci30819DroneTestC5Ev]+0x37): undefined reference to `csci3081::Drone::Drone()'
/usr/bin/ld: /tmp/ccWt2oid.o: in function `csci3081::RobotTest::RobotTest()':
robot_test.cc:(.text._ZN8csci30819RobotTestC2Ev[_ZN8csci30819RobotTestC5Ev]+0x37): undefined reference to `csci3081::Robot::Robot()'
collect2: error: ld returned 1 exit status
make[1]: *** [Makefile:16: /project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/test/csci3081tests] Error 1
make[1]: Leaving directory '/project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31/project/tests'
make: *** [Makefile:67: test] Error 2
</pre>



+ :leftwards_arrow_with_hook:  Dynamic Check that file exists. (Test not run because of an earlier failing test)

+ :leftwards_arrow_with_hook:  Dynamic Check that file exists. (Test not run because of an earlier failing test)

---

+ :heavy_check_mark:  Check that make clean compiles.



+ :heavy_check_mark:  Change into directory "..".


#### Checkout to branch

+ :heavy_check_mark:  Run git ls-remote to check for existence of specific branch- Branch master found

+ :heavy_check_mark:  Checkout master branch.




#### Necessary Files and Structure

+ :heavy_check_mark:  Check that directory "project" exists.

+ :heavy_check_mark:  Check that directory "project/bin" exists.

+ :heavy_check_mark:  Check that directory "project/docs" exists.

+ :heavy_check_mark:  Check that directory "project/src" exists.

+ :heavy_check_mark:  Check that directory "project/tests" exists.

+ :heavy_check_mark:  Check that directory "project/web" exists.

+ :heavy_check_mark:  Check that file "project/Makefile" exists.

---


#### Compile Simulation and Tests

+ :heavy_check_mark:  Change into directory "project".

+ :heavy_check_mark:  Copy directory "Files for correct version".



+ :heavy_check_mark:  Check that make  compiles.



+ :x:  Check that make test compiles.

    Make compile fails with errors:.
<pre>cd tests; make
make[1]: Entering directory '/project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31/project/tests'
mkdir -p /project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/test
/soft/gcc/7.1.0/Linux_x86_64/bin/g++ -std=c++11 -fPIC  -Wl,-rpath,/project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/lib -I/project/grades/Spring-2021/csci3081/dependencies/include -I../src -I../include -I. -I.. -L/project/grades/Spring-2021/csci3081/dependencies/lib -L/project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/lib *.cc -lgtest_main -lgtest -lgmock -pthread -lcsci3081proj -lEntityProject -lCppWebServer -lwebsockets -lssl -lcrypto -lz -o /project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/test/csci3081tests
/usr/bin/ld: /tmp/ccy2ljpy.o: in function `csci3081::DroneTest::DroneTest()':
drone_test.cc:(.text._ZN8csci30819DroneTestC2Ev[_ZN8csci30819DroneTestC5Ev]+0x37): undefined reference to `csci3081::Drone::Drone()'
/usr/bin/ld: /tmp/cc4iP24w.o: in function `csci3081::RobotTest::RobotTest()':
robot_test.cc:(.text._ZN8csci30819RobotTestC2Ev[_ZN8csci30819RobotTestC5Ev]+0x37): undefined reference to `csci3081::Robot::Robot()'
collect2: error: ld returned 1 exit status
make[1]: *** [Makefile:16: /project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31-build/test/csci3081tests] Error 1
make[1]: Leaving directory '/project/grades/Spring-2021/csci3081/student-repos/Lab_13_Feedback/repo-iter3-10-31/project/tests'
make: *** [Makefile:67: test] Error 2
</pre>



+ :leftwards_arrow_with_hook:  Dynamic Check that file exists. (Test not run because of an earlier failing test)

+ :leftwards_arrow_with_hook:  Dynamic Check that file exists. (Test not run because of an earlier failing test)

---

+ :heavy_check_mark:  Check that make clean compiles.



---

---

