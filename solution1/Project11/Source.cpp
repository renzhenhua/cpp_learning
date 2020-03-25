﻿//
//#include <iostream>
//#include"Human.h"
//#include"Men.h"
//#include"Women.h"
//#include"func.h"
//#include"A.h"
//#include"C.h"
//
////class C;//类C声明
////class A
////{
////private:
////	int data;
////	friend class C;
////};
////
////class C
////{
////public:
////	void callCAF(int x, A &a)
////	{
////		a.data = x;
////		std::cout << a.data << std::endl;
////	}
////	void callCAF2(A &a)
////	{
////		a.data;
////	}
////};
//
//int main()
//{
//	//类之间有层次关系
//	//把车类，当成父类(也叫基类，超类)， 派生出卡车，轿车，叫做子类(派生类)
//	//有父类，子类，构成层次关系，叫继承。面向对象程序设计的核心思想之一
//	//父类中定义一些公用的成员变量，成员函数
//	//我们通过继承父类来构建新类：子类
//	//所以写代码时只需要写和子类相关的内容即可
//	//子类会比父类更加庞大
//
//
//	//class Men :public Human //表示Men是Human的子类
//	//class 子类名 :继承方式 父类名
//	//继承方式（访问权限）public, protected, private
//	
//	//派生类对象定义时调用构造函数的顺序
//	//Men men;//当定义子类对象时，是要调用父类和子类的构造函数的，而且父类的构造函数的的函数体先执行，子类的构造函数的的函数体后执行
//
//	//public, protected, private
//	//protected:只允许本类或者子类的成员函数来访问
//
//	//Men men;
//	//men.funcpub();//调用父类函数
//
//	//子类一旦有了一个同名函数，会导致，不管在父类中有几个同名函数，子类中都无法访问到
//	//如果我们确实想调用父类中的同名函数
//	//（1）在子类的成员函数中，用“父类::函数名”强制调用父类函数
//	//（2）using
//	//c++11,让父类同名函数在子类中可见
//	//通过using，可以让父类的同名函数在子类中可见，就是“父类同名函数在子类中以重载的方式来使用”
//	//men.samenamefunc(12);
//	//men.samenamefunc();
//	//说明 
//	//a)using Human::samenamefunc 只能指定函数名，则凡是基类中的public的samenamefunc在子类中都可见。
//
//	//b)using 引入的主要目的是用来实现在子类对象中调用父类的重载版本。该函数在父类中的参数类型，个数和子类中总有不同
//
//
//
//	//基类指针，派生类指针
//	//Men men;
//	//Human *phuman = new Human();
//	//Men *pmen = new Men;
//
//	//新玩法：父类指针可以new一个子类对象
//	//Human *phuman = new Men;//ok
//	//Men *pmen = new Human;//error
//	//phuman->funchuman();
//	//phuman->funcmen();//不可以，虽然new出来一个子类对象，但是你是父类指针，无法调用子类成员函数
//	//既然父类指针没有办法调用子类成员函数，用父类指针new一个子类对象用处：
//	
//	//phuman -> eat();//调用父类的eat函数。因为phuman是父类指针
//
//	//问题:有没有一个解决方法，我们只需要定义一个对象指针，就可以调用父类，以及各个子类的同名函数。
//	//这个对象指针类型必须是父类类型
//	//如果想通过一个父类指针调用父类，子类中的同名同参函数，对这个函数也是有要求：
//	//在父类中，eat函数声明前必须加virtual声明成虚函数
//	//一旦某个函数（在基类中）被声明成了虚函数，那么所有派生类中它都是虚函数
//
//	//Human *phuman = new Men;
//	//phuman->eat();
//	//phuman->Human::eat();//可以调用父类的eat函数
//	//delete phuman;
//
//	//phuman = new Women;
//	//phuman->eat();
//	//delete phuman;
//
//	//phuman = new Human;
//	//phuman->eat();
//	//delete phuman;
//
//	//为了避免在子类中写错虚函数，在c++11中，可以在函数声明这里增加一个override关键字
//	//这个关键字用在“子类”中，而且是虚函数专用
//	//override就是用来说明派生类的虚函数，你用了这个关键字以后，编译器就会认为你这个eat是覆盖了父类中的同名函数
//	//（只有虚函数才存在子类可以覆盖父类中同名函数的问题），那么编译器就会在父类中找同名同参的虚函数
//	//如果没找到，那么编译器就会报错，这样，如果不小心在子类中把虚函数写错了名字，写错了参数，编译器能够帮你纠错
//
//	//final,final也是虚函数专用，是用在“父类”，如果我们在父类的函数声明中加了final，那么任何尝试覆盖该函数的操作都将引发错误。
//
//	//调用虚函数执行的是“动态绑定”，表示的就是我们程序在运行的时候才能知道调用了子类的eat()虚函数
//	//动态绑到Men, 还是绑到Women上，取决于new的是Men还是Women
//	//动态绑定：运行的时候才觉得你得phuman对象绑定到哪个eat()函数上运行
//	/*std::cout << std::endl;
//	Men men;
//	men.eat();
//
//	Women women;
//	women.eat();
//
//	Human human;
//	human.eat();*/
//	//多态性
//	//多态性只是针对虚函数来讲的
//	//随着虚函数提出，面向对象编程里边有一个概念“多态性”
//	//多态性：体现在具有继承关系的父类和子类之间，子类重新定义（重写）父类的成员函数eat()，同时父类把这个eat()函数声明成了virtual虚函数
//	//通过父类指针，只有到了程序运行时期，找到动态绑定到父类指针上的对象，这个对象有可能是某个子类的对象，也可能是父类对象
//	//然后系统内部实际上是查一个虚函数表，找到函数eat()的入口地址，从而调用父类或者子类的eat()函数，这就是运行时期的多态性
//
//	//纯虚函数
//	//纯虚函数是在基类中声明的虚函数，但是它在基类中没有定义，但是要求任何派生类都要定义该虚函数自己的实现方法
//
//	//一旦一个类中有一个纯虚函数了，那么就不能生成这个类的对象了。这个类成为抽象类
//	//抽象类不能用来生成对象，主要目的是用来统一管理子类对象	
//
//	//1)函数纯虚函数的类叫抽象类，不能用来生成该类对象，主要用来当作基类来生成子类用的
//	//2）子类中必须要实现该基类中定义的纯虚函数
//	
//	//Human human;//error
//	//Human *phuman = new Human;//error
//	/*Human *phuman = new Men;
//	phuman->eat2();*/
//	
//
//	//基类的析构函数一般要写成虚函数（虚析构函数）
//    //Men men;
//	//Men *pmen = new Men;
//	//delete pmen;
//
//     
//	//Human *phuman = new Men;
//	//delete phuman;//没有执行子类的析构函数
//	//结论：用基类指针new子类的对象，在delete的时候系统不会调用派生类的析构函数
//	//解决方式
//	//把父类的析构函数写成虚函数
//
//	//在public继承中，基类对派生类及其对象的操作，只能影响到那些从基类继承下来的成员
//	//如果想要用基类对非继承成员进行操作，则要把基类这个函数定义为虚函数，析构函数自然也如此
//	//另外就是基类中的析构函数的虚属性也会被继承给子类，这样的话子类的析构函数也就自然而然的成为了虚函数，虽然名字和基类中的虚函数名不同
//	//delete phuman的时候，肯定要调用父类的析构函数，但父类析构函数中，它要是想要调用子类Men的析构函数，那么
//	//Human这个类中的析构函数就要声明为virtual，也就是说c++为了获得运行时的多态行为，所调用的成员函数必须是virtual
//	
//	//虚函数会增加内存开销，类里面定义虚函数，编译器就会给这个类增加虚函数表，在这个表里放虚函数指针
//	
//
//	//友元函数
//	//只要让函数func成为类Men的成员函数，那么func这个函数就能访问类Men的所有成员（成员变量，成员函数），private,protected,public
//	
//	
//
//	//Men men;
//	//func(men);//打印“test”
//
//	//友元函数是给函数，通过声明为某个类Men的友元函数，它就能访问这个类（Men）的所有成员，包括private,protected,public
//	
//	
//	//友元类： 类 可以把其它的类定义为友元类。如果你是我的友元类，那么你就可以在你的成员函数中访问我所有的成员
//	//修改类A，让类C成为类A的朋友（让类C成为类A的友元类）
//	/*A a;
//	C c;
//	c.callCAF(3,a);*/
//
//	//注意：每个类负责控制自己的友元类和友元函数，所以：
//	//a)友元关系不能被继承；
//	//b)友元关系是单向的，比如上面类C是类A的友元类，但是类A不是类C的友元类
//	//c)友元关系没有传递性，比如类B是类A的友元类，类C是类B的友元类，这并不代表类C是类A的友元类
//
//
//	//友元成员函数
//	//必须注意代码组织结构，因为有声明和定义依赖关系
//
//	A a;
//	C c;
//	c.callCAF(3, a);
//
//	//总结：friend:
//	//优点：允许在特定情况下某些非成员函数访问类的protected,private成员，从而提出友元成员函数这么一个概念
//	//使访问protected，private成员更灵活
//
//	//缺点：破坏了类的封装性，降低了类的可靠性和可维护性
//	return 0;
//}
//
//
