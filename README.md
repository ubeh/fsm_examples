# FSM library examples

These are some examples that show how to integrate boost::msm and the new boost:sml library in a 
larger class that has much more responsibilities than just implementing the state machine logic. 

### Example 1: boost::msm 

This example demonstrates how to use a boost::msm as a class member. To achieve this, an abstract 
class is used. I recommend Christophe Henry's Meeting C++ talk 
(https://meetingcpp.com/index.php/talkview13/items/17.html) for further information about 
boost::msm. 

### Example 2 boost::msm refactored 

This example demonstrates how to use boost::msm as a class member without the need for an abstract 
class. This is done by using the Pimpl idiom. As a result the API and the implementation is 
simplified. 

### Example 3: boost::sml 

This example is a reimplementation of the first boost::msm example with boost:sml. Again, an 
abstract class is used. 

### Example 4: boost::sml refactored

This example is complementary to the second boost::msm example. It shall demonstrate how to use 
boost::sml as a class member without the need for an abstract class. This example does not compile 
and needs some work. Suggestions are very much appreciated. 
