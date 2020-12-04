#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QApplication>
#include <QTranslator>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->menu_Language, &QMenu::triggered, this, [this] (QAction *action) {
		if (action == ui->action_Japanese) {
			if (ts == nullptr) {
				ts = new QTranslator;
				ts->load(":/translations/multi_language_ja_JP.qm");
				qt_ts = new QTranslator;
				qt_ts->load(":/translations/qtbase_ja.qm");
			}
			qApp->installTranslator(ts);
			qApp->installTranslator(qt_ts);
		} else {
			qApp->removeTranslator(ts);
			qApp->removeTranslator(qt_ts);
		}
	});
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{
	if (event->type() == QEvent::LanguageChange) {
		ui->retranslateUi(this);
	}
	QMainWindow::changeEvent(event);
}
