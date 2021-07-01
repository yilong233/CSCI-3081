/*! \mainpage CSCI 3081 Delivery Simulation project
*
* This file is currently a stub. To view project startup instructions, check Lab 10
*
* To generate documentation, first build the project with `make` in the `project` directory.
* Next, navigate to `project/docs` and run `doxygen Doxyfile`.
* Then open `project/docs/html/index.html` in your web browser to view the documentation.
*
*
* \tableofcontents
*
* \section intro_sec Introduction
*
* For this project, I will create a package delivery simulation.
* Now many express companies are using drones, robots and self driving trucks to develop automatic delivery systems, such as Amazon, FedEx, ups and other companies.
* For the iteration of this project, iteration 1 focuses on laying the foundation for the complete project.
* I will only create the package delivery system by drone.
* The overall goal of this time is to get the drone to pick up the package and deliver it to customers.
* In the process, I will have to create the following classes: customer, drone, package, Vector3D, vector2d and battery.
*
* \section  inter_one_sec Iteration 1
*
* 1. Façade Design Pattern  
*
* This project uses a Façade Design Pattern. This pattern provides a simplified interface to a set of interfaces within a system
* and thus it hides the complexities of the subsystem from the client. This reduces the number of objects handled by the client
* and makes the subsystem more convenient to use.
*
* 2. Composite factory pattern
*
* In this program, Drone. Customer and Package are three kinds of entities. They are is-a relationship.
* That means these three classes inherit from class EntityBase. And IEntity is the interface of the EntityBase.
* First, I create each of Entity by if-else statements. But it breaks the Open-Closed Principle, which is Entities should be
* open for extension but closed for modification. If we want to add a new kind of entity, we will change the if-else statement.
* Then I think Composite Factory Pattern would be a good choice for this project.
*
* The advantage of Composite Factory Pattern deferred the creation to the factory subclass. Instead of creating objects directly in the factory,
* we directly encapsulate a small factory, each factory is responsible for creating its own subclass. And we also have a class called CompositeFactory,
* which inherit from IEntityFactory. It acts as a middleman, assigning the CreateEntity task issued by IEntityFactory to the appropriate factory. He will
* traverse all the factories added to his company (vector of factories), find the suitable factory, and pass the return value to IEntityFactory. In this way,
* there is no if-else statement, and there is no problem that the extension does not satisfy OCP.
*
* Its shortcomings are also obvious. The Composite_Factory makes the program structure verbose, with one more class than the Factory Method pattern.
* This is unfriendly to people who are seeing the program for the first time.
*
* \section  inter_two_sec Iteration 2
*
* In interation2, we add some news things, there are :
* First, we add the observers. We can add and remove it to drone, robot and packages from the delivery_simulation.
* This function can allow us to see the feedback on the left hand websites.
* Then, we allow for multiple packages to be delivered in a simulation, which means that the simulations to be capable of delivering multiple packages, utilizing multiple robots/drones.
* Next, we implement a different drone route using the Strategy Pattern. There are three method, smart, beeline and parabolic.
*
* 1. Strategy Pattern
* In the Strategy pattern, we will have three routes, they are smart, beeline and parabolic.
* As for the smart path, it is same as the path in the interation1. As a result, we will not introduce it here.
* As for the beeline path, we just need to raise the drone to a certain height to prevent it from colliding with buildings.
* Then go straight to the top of the package or the customer, and drop vertically.
* As for the parabolic path, we We determine a parabola through the starting point, the end point and the highest point, and then generate 100 three-dimensional coordinates.
*
* The advantage of the Strategy Pattern is:
* By encapsulating the algorithms separately, we can easily introduce new algorithms that conform to the same interface.
* The strategy allows customers to choose the algorithm they want without using a "switch" statement or a series of "if else" statements.
* The application can switch policies at run time.
*
* The disadvantage is:
* The application must know to choose all the right policies for the right situation.
* Context and policy classes usually communicate through the interface specified by the abstract policy base class.
*
*
* 2. Observers Pattern Design  
*
* We create the SetObserver() function in the entity_base.h, and the NotifyForDrone(), GetState(), and the SetState() functions are all in the Drone class.
* And the notification function will be positioned in the drone class, which will use the OnEvent() function.
* Finally, we add the AddObserver() and RemoveObserver() function in the delivery_simulation.
*
* \section teamwork Teamwork
*
* Priority1.1 is Yilong's task. Priority1.2 is Maria's task.  
* Priority2.1 is Jiazheng's task. Priority2.2 is Xiyuan's task. Priority2.3 Jiazheng and Yilong work together.  
* Priority3 is Jiazheng's task.  
* Priority4 is Xiyuan's task.  
* Besides, Xiyaun also records the groupwork meeting. And Yilong works on the documentation, (just like the doxygen, comments and UML).  
*
* The date: 04/01/2021  
* People: Maria Gwanganalie, Yilong Liu, Jiazheng Chen, Xiyuan Li  
* Discussion: Priority1.2 is Maria's task. And we discussed our own task. We also discussed how to fix 
* the google test for iteration 1 and what the robot class should look like.  
* The date: 04/02/2021  
* People: Maria Gwanganalie, Yilong Liu, Jiazheng Chen, Xiyuan Li  
* Discussion:  Yilong Liu, Jiazheng Chen, Xiyuan Li did the priority2 together. We discussed the multiple packages* 
* together. And Jiazheng finished the multiple packages, Xiyuan finished Observe Packages, Yilong finished Observe Drone/Robot  
* The date: 04/13/2021  
* People: Maria Gwanganalie, Yilong Liu, Jiazheng Chen, Xiyuan Li  
* Discussion:  We discussed the tasks for the final deliverable of iteration 2. Jiazheng finished priority3. 
* Maria did priority4. Yilong finished the Doxygen document and UML. Xiyuan finished google tests,
* github issues and teamwork documents.  
* The date: 04/19/2021  
* People: Maria Gwanganalie, Yilong Liu, Jiazheng Chen, Xiyuan Li  
* Discussion:  We discussed how priority 4 should be. Maria had problem on how to rescheduled packages.
* We finished it together.
*
* Everyone is fully contributed  
*
* \section uml_diag_sec UML Diagram
*
* Here is my final UML digram for interation 2:  
* \image \docs\UML_interation2.png
* 
* \section  inter_three_sec Iteration 3
* \section iteration feature:
* The new feature we implemented for this iteration is that we add a way for dones to gain battery life. We use a recharge drone to recharge to 
* the dead drones and robots. Packages will be scheduled to the carrier(drones/robots) whicy is cloest to them. If there is no drones/robots available, 
* the package will be add to the queue named undeliveredpackage. Carriers movements consume electricity and when it runs out, it is added to the 
* emptycarriers queue. When Carrier is in non-dynamic, each update will check whether there is an undeliveredPackage. Assign this package to it.
* Drones have the function of charging other carriers. When a drone with an battery capacity greater than 1000 is in non-dynamic, each updates will 
* check if there is an emptycarriers. If do, the recharge drone will fly to them and charge them. 
*
* The most difficult part is that how to make the dead drones move again. We tried several methods but failed. At first we just make the recharge drone
* move to the dead drone if the battery is empty at once. We then change the logic, we create a queue for dead drones. In that case, when there are 
* no recharge drones available, the dead drone can still get recharged and move again. To implement that feature, our recommendation is that to run 
* ./bin/run.sh scenes/all_features1.json, which is our own scenes for testing the new features. In that scenes, there are 2 drones, one is in low battery, and 
* 2 robots, one is in low battery, too. There are 2 customers and 5 packages. The low battery drone and robot will stop moving after picking the package 
* first time. The other drone will come and recharge the low battery drone and robot after it delivered its own package. It will recharge the robot first, since 
* the robot run out of its battery first. Then the robot and drone will start moving again and continue sending packages.
*
* Unfortunately, we were not able to create tests for classes that were heavily implemented on other classes, because we failed to compile some of test file.
* 
* \section Design Pattern
* \image \docs\itr3_UML.png
* As the UML shows, the robot, drone, package and observer are all connect to the observer, once one of them change, the observer can observe this change. Then
* others can get to know this change.
* 
* As for the design pattern, we still use observer pattern this time. Since we need to know when a drone/robot is run out of battery, which the recharge drones 
* can know and come to recharge them. The observer pattern works fine for this kind of problems. The obserber pattern defines a one-to-many dependency 
* between objects. When one object's state changes, all objects that depend on it are notified and automatically updated.When an object changes, the object 
* that pays attention to it is notified. It's also easier for us to fix the code. 
* 
* We considered to use Composite factory pattern to add a new factory called recharge drone pattern. However, we finially give up these pattern since in that
* case, we need to create another entity called recharge drone and make sure it would not be scheduled to a package all the time. Since recharge drone is still a
* drone, that will be a a lot of work. Sometimes it will cause confusion to the whole system.
*
* \section teamwork Teamwork 
* The date: 04/25/2021
* People: Maria Gwanganalie, Yilong Liu, Jiazheng Chen, Xiyuan Li
* Discussion: This meeting we discussed and determined which feature we want to implemented and splited the work. We decided to 
* do the recharge one.
*
* The date: 04/28/2021
* People: Maria Gwanganalie, Yilong Liu, Jiazheng Chen, Xiyuan Li
* Discussion:  We discussed the main logic of how recharge drone work. We decided we wanted to implement this feature by adding a recharge drone that would be in
* charge by giving its battery life other drones which will be designated to a drone with a lot of battery life.
* Jiazheng fixed some problems and bugs we have in the previous section. 
* Maria began to work on the recharge drone.
* 
* The date: 04/29/2021
* People: Maria Gwanganalie, Yilong Liu, Jiazheng Chen, Xiyuan Li
* Discussion:  Maria make the recharge drone move to the dead drone, however, the dead drone could not move again. We decided why we have 
* this problem and how can we solve it. 
* 
* The date: 04/30/2021
* People: Maria Gwanganalie, Yilong Liu, Jiazheng Chen, Xiyuan Li
* Discussion:  We still try to make the dead drone move again based on Maria's code. Sometimes the recharge drone will come and pick the package up. Sometimes 
* the recharge drone won't move. Yilong and Xiyuan works on making the dead drone move again and the document. Maria works for google test. 
* Jiazheng fixed the bug. We finally finished it.
* 
* As is mentioned above, Maria finished the part of recharge drone and google test.
* Jiazheng finished the recharge drone and fixed all the bugs.
* Yilong finished the UML and doxygen and debug.
* Xiyuan finished the teamwork document and mainpage and debug.
* Everyone is fully contributed.
* 
* \section gettint_started_sec Getting Started
* First, build project. (MUST be within project/ directory)
* run:
*
* cd project
* make

* Then run project.
* run:
*
* ./bin/run.sh
*
* Last, Open up Firefox and browse to http://127.0.0.1:8081/
*
* To test the feature for iteration 3
* run:
* ./bin/run.sh scenes/all_features1.json
*
*/
