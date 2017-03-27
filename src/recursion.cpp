/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;

int gcd(int a, int b) {
    if ( b == 0 ){
        return b ;
    }
    else {
        return  gcd( b , a % b) ;
    }
}

void serpinskii(GWindow &w, int leftX, int leftY, int size, int order) {
    // your code here
    cout << "[recursion serpinskii called]" << endl;
    if (order == 1 ){
    
        w.drawLine(leftX,leftY,size+leftX,leftY) ;
        w.drawLine(size+leftX,leftY,size / 2.0 + leftX , size*sqrt(3) /2.0+ leftY) ;
        w.drawLine(size/2.0+leftX,size*sqrt(3)/2+leftY,leftX,leftY) ; 
    }

    else if ( order <= 0 ){
    
        throw ("wrong!") ;
        return ; 
    }

    else {
    
        serpinskii (w ,leftX , leftY ,size /2.0 , order - 1 ) ;
        serpinskii (w , leftX + size /2.0 , leftY , order - 1 ) ;
        serpinskii (w,  leftX  +size /4.0 , leftY + size/2.0 *sqrt(3)) ;

    }
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    // your code here
    cout << "[recursion flood fill called]" << endl;
    if ( newColor == image.getRGB(x,y)) {
        return 0;
    }

    else 
        return ChangeAndSum(image , x, y , newColor , image.getRGB(x,y)) ; 
}

int ChangeAndSum( GBufferedImage& image , int x ,int y , int newColor ,int old ) {

    if ( image.inBounds(x,y) && image.getRGB(x,y)==old) {
    
        return 1 + ChangeAndSum(image,x,y+1,newColor,old) + ChangeAndSum(image,x,y-1,newColor,old) + ChangeAndSum(image,x+1,y,newColor,old) + ChangeAndSum(image,x-1,y,newColor,old) ; 
    }

    else return 0 ;
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    // your code here
    cout << "[recursion personal curriculum called]" << endl;
    Map<string , int> had ;
    had.put(goal,1) ;
    DeepFind(prereqMap , goal , had ) ;
    cout << goal << endl ; 
}

void DeepFind( Map<string, Vector<string>> & prereqMap , string goal , Map<string ,int > had ){

    if ( prereqMap.get(goal).isEmpty() ) {
    
        return ;
    }

    else {
    
        had.put(goal,1) ;
        for ( string concept : prereqMap.get( goal)) {
        
            DeepFind( prereqMap , concept , had ) ;

            if ( !had.contiansKey(concept) ){
            
                cout << concept << endl ;
            }
            had.put(concept,1) ;
        }
    }
}

string getres(Map<string , Vector<string> > & grammer , string symbol , string out) {

    if ( !grammer.containsKey(symbol)){
    
        return symbol ;
    }

    else {
    
        string random = grammer.get(symbol).get(randomInteger( 0, grammar.get( symbol ).size() -1 ) )  ; 
        TokenScanner scanner(random) ;
        while (scanner.hasMoreTokens()) {
        
            string next = scanner.nextToken() ;
            out += getres(grammer,next,out) ;
        }
    }
    return out ; 
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    // your code here
    cout << "[recursion generate called]" << endl;
    return getres(gammar , symbol , " ") ;
}