#include <iostream>
#include "OsgViz.hpp"
#include "plugins/viz/Primitives/PrimitivesFactory.h"
#include <unistd.h>//sleep
#include <stdio.h>



int main(int argc, char** argv)
{
	printf("getting instance\n");
	fflush(stdout);
	osgviz::OsgViz *osgViz = osgviz::OsgViz::getInstance();

	//load lib with some helpful primitives
	printf("load plugin\n");	fflush(stdout);
	osgviz::PrimitivesFactory *primitivesfactory = osgViz->getVisualizerPlugin< osgviz::PrimitivesFactory >("PrimitivesFactory");

	if (!primitivesfactory){
		printf("plugin not found\n");	fflush(stdout);
	}
	
	osg::ref_ptr<osgviz::Object> grid = primitivesfactory->createGrid();
	osgViz->addChild(grid);

	osg::ref_ptr<osgviz::Object> arrow = primitivesfactory->createArrow();
	arrow->rotate(M_PI/2.0,osg::Vec3d(0,1,0));
	arrow->setName("Arrow");
	osgViz->addChild(arrow);

	osg::ref_ptr<osgviz::Object> axes = primitivesfactory->createAxes();
	osgViz->addChild(axes);
	
	printf("creating window\n");fflush(stdout);

	int winid = osgViz->createWindow();


	osgviz::HUD* hud = osgViz->getWindowManager()->getWindowByID(winid)->addHUD(1920,1080);

//	osg::ref_ptr<osgviz::Object> hudarrow = primitivesfactory->createArrow();
//	hudarrow->setPosition(100,100,0);
//	hudarrow->setScale(200,200,200);
//	hud->addHudObject(hudarrow);


    osg::Geode* geode = new osg::Geode();
    osgText::Text* text = new  osgText::Text;
    geode->addDrawable( text );
    osg::Vec3 position(150.0f,800.0f,0.0f);
    text->setPosition(position);
    text->setText("Head Up Displays are simple :-)");
    hud->addHudObject(geode);





    osg::ref_ptr<osgviz::Object> axes2 = primitivesfactory->createArrow();
    axes2->setName("Head Up Displays are really simple :-)");
    //axes2->displayName(0.3);
    axes2->setScale(100,100,100);
    axes2->setPosition(100,100,0);
    axes2->rotate(M_PI/2.0,osg::Vec3(1,0,0));
    hud->addHudObject(axes2);


    osg::ref_ptr<osgviz::PrimitivesFactory::Shape> shape = primitivesfactory->createShape(osgviz::PrimitivesFactory::BOX,100,100,0);
    shape->setPosition(500,500,0);
    //shape->setScale(100,100,100);
    shape->setName("BoxBoxBoxBox");
    shape->displayName(10);
    shape->setColor(1,0,0,0.5);

    hud->addHudObject(shape);

    osg::ref_ptr<osgviz::PrimitivesFactory::Shape> shape1 = primitivesfactory->createShape(osgviz::PrimitivesFactory::BOX,0.5,0.5,0.5);
    shape1->setColor(1,0,0,0.5);
    //shape1->setPosition(0.5,0.5,0.5);
    osgViz->addChild(shape1);


//    osg::ref_ptr<osgviz::Object> image = primitivesfactory->loadImage("test.png");
//    //shape1->setPosition(0.5,0.5,0.5);
//    image->setPosition(1000,500,0);
//    hud->addHudObject(image);

	//sleep(1);
	//you can create multiple ones:
	//osgViz->createWindow();

	//this starts a update thread for the visualisation, requires locking in the other threads:
	//osgViz->lockThread();
	//do updates
	//osgViz->unlockThread();
	printf("startThread\n");fflush(stdout);
	osgViz->startThread();

	//or don't start the thread and update manually using osgViz->update();


	while (true){
		//osgViz->lockThread();
		//do updates
		//osgViz->unlockThread();
		//osgViz->update();
		//printf("sleep\n");fflush(stdout);

		sleep(5);
//		osgViz->getWindowManager()->getWindowByID(0)->setFullscreen(true);
//		sleep(5);
//		osgViz->getWindowManager()->getWindowByID(0)->setFullscreen(false);
//		sleep(5);
//		osgViz->getWindowManager()->getWindowByID(0)->setWindowGeometry(150,150,1240,768);
//		sleep(5);

	}

	return 0;
}
