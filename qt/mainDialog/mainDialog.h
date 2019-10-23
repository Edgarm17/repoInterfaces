
#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

 class QCheckBox;
 class QLabel;
 class QLineEdit;
 class QPushButton;
 class QListWidget;

 class MainDialog : public QDialog
{
     	Q_OBJECT

 public:
     	MainDialog(QWidget *parent = 0);
     
    
public slots:
  
  	void slotBackward(const QString &str, Qt::CaseSensitivity cs);
  	void slotFordward(const QString &str, Qt::CaseSensitivity cs);   	

 private:
 	
	QListWidget *back;
	QListWidget *ford;
     	QLabel *labelBack;
     	QLabel *labelFord;
     	
};
#endif

