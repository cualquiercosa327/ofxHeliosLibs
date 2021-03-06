#include "ofxMatrixTransformImageRef.h"


ofxMatrixTransformImageRef::ofxMatrixTransformImageRef ( )
{
	scale = 1.0f ;
	rotation = 0.0f ;
	bInheritAlpha = false ;
	setup( ) ; 
	//alpha = 0 ;
}
    
ofxMatrixTransformImageRef::~ofxMatrixTransformImageRef ( )
{
    image->clear() ; 
}

void ofxMatrixTransformImageRef::setup ( ) 
{
	ofxMatrixTransformObject::setup() ;
	ofxAlphaStackItem::setup ( ) ; 

	scale = 1.0f ;
	rotation = 0.0f ;
	bInheritAlpha = false ;
}

void ofxMatrixTransformImageRef::draw ( )
{
	pushMatrix( ) ;
        ofSetColor ( 255 , 255 , 255 , getOFAlpha() ) ;
		if ( image != NULL && image->bAllocated() ) 
		    image->draw ( image->width * -_anchor.x , image->height * -_anchor.y ) ;
	popMatrix( ) ;
}

void ofxMatrixTransformImageRef::loadImage( string path , float _x , float _y , ofPoint anchor , float _alpha )
{
	if ( path != "" ) 
		image->loadImage( path ) ;
	x = _x ;
	y = _y ;
    _anchor = anchor ;
    alpha = _alpha ;
	imageFilePath = path ; 
}

void ofxMatrixTransformImageRef::setImageProperties( ofImage * img , float _x , float _y , ofPoint anchor , float _alpha  )
{
	image = img ;
    x = _x ;
    y = _y ;
    _anchor = anchor ;
    alpha = _alpha ;
			
	bLoaded = false ; 
}

void ofxMatrixTransformImageRef::clear( ) 
{
	bLoaded = false ; 
	image->clear() ; 
}

void ofxMatrixTransformImageRef::setImagePath ( string path ) 
{
	//Could do more here
	//Check if it's the same Path ? Clear the image if it's already load, etc 
	imageFilePath = path ;
}
  