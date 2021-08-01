// #include <iostream>

// int main(int argc, const char* argv[]) {
// 	std::cout << "hello world" << std::endl;
// 	system("pause");
// 	return 0;
// }

#include <QObject>
#include <QtWidgets/QApplication>
#include <QMainWindow>
#include <qDebug>
#include <QLabel>

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	cout << "hello cmake!" << endl;

	QMainWindow* view = new QMainWindow;
	view->setWindowTitle("upper monitor");
    view->resize(400, 300);
	view->show();

	return app.exec();
}


/**
 * 我们在学习标准C++的时候，
 * 都知道每个应用程序运行时都会先进入入口点函数main，
 * 而当从main函数跳出时程序就结束了。
 * 
 * 在Windows编程里面，也是一样的，只是我们的入口点函数不叫main，
 * 叫WinMain，这个函数不同于main，我们不能乱来，它的定义必须与声明保持一致。
 */
// using namespace std;
// int WinMain(int argc, char* argv[]) {
// 	//没有输出
// 	cout << "hello cmake! winmain" << endl;
// 	//弹出黑框
// 	system("pause");
// 	//没有输出
// 	cout << "hello cmake! winmain" << endl;
// 	system("pause");
// 	return 0;
// }
