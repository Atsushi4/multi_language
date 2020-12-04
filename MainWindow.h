#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QTranslator;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

protected:
	void changeEvent(QEvent *event) Q_DECL_OVERRIDE;

private:
	Ui::MainWindow *ui;
	QTranslator *ts = nullptr;
	QTranslator *qt_ts = nullptr;
};
#endif // MAINWINDOW_H
