# Fsm library examples

These are some examples of how to use the boost::msm and the new boost:sml 
libraries. 

### Example 1: boost::msm 

This example demonstrates how to use a boost::msm as a class member. To achieve 
this, a pure virtual class is used. For further information, I recommend 
Christophe Henrys Meeting C++ talk (https://meetingcpp.com/index.php/talkview13/items/17.html). 

### Example 2 boost::msm refactored 

This example demonstrates how to use a boost::msm as a class member. In this 
version, we got rid of the interface and have simplified the interface. 

### Example 3: boost::sml 

This example is complementary to the first boost::msm example. It demonstrates 
how to use a boost::sml as a class member. To achieve this, a pure virtual 
class is used. 

### Example 4: boost::sml refactored

This example is complementary to the second boost::msm example. It shall 
demonstrate how to use a boost::sml as a class member without a virtual class
as interace but instead by using a forward declaration of the fsm. This example 
does not compile and needs some work. 
