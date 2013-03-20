#pragma once

#include "ofMain.h"

class ofxTransitionItem
{
	public :
		TransitionItem() {
		    bInTransition = false ;
		} ;

		virtual void transitionIn( ofVec2f _offset , float time = 0.5f , float delay = 0.0f ) {  }
		virtual void transitionOut( ofVec2f _offset , float time = 0.5f , float delay = 0.0f ) {  }

        void transitionIn( float time , float delay )
        {
            if ( bInTransition ) return ;

            bInTransition = true ;
            
            //Tweenzor::add( &alpha , alpha , 1.0f , delay , time , EASE_OUT_QUAD ) ;
            //Tweenzor::addCompleteListener( Tweenzor::getTween( &alpha ) , this , &TransitionItem::transitionInComplete ) ;
        }

        void transitionOut( float time , float delay )
        {
            if ( bInTransition ) return ;

            bInTransition = true ;

            //Tweenzor::add( &alpha , alpha , 0.0f , delay , time , EASE_OUT_QUAD ) ;
            //Tweenzor::addCompleteListener( Tweenzor::getTween( &alpha ) , this , &TransitionItem::transitionOutComplete ) ;

        }

        void transitionInComplete( float * args )
        {
            bInTransition = false ;
        }

        void transitionOutComplete( float * args )
        {
            bInTransition = false ;
        }

    protected :
		bool bInTransition ;

};