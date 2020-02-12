#ifndef POWERUP_H
#define POWERUP_H

#include <QPainter>
#include <QImage>
class PowerUp{

public:
	
	PowerUp(float, float, QImage);

	float posX;
	float posY;
	float width;
	float height;
	QImage imagen; 
	
        void pintarPU(QPainter &);
        void resizePU();
	
private:

};

#endif 
