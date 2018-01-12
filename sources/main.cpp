#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <aruco/aruco.h>
#include <iostream>

using namespace cv;
using namespace aruco;
using namespace std;

#define ESC_KEY      27
#define ESC_KEY_VM   1048603 // should be 27

#define Q_KEY        113
#define Q_KEY_VM     1048689 // should be 113

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: app nom_de_l_image" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if(!image.data )
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Affichage", WINDOW_AUTOSIZE );
    //imshow( "Affichage", image );

    // création d'un détecteur de marqueurs
    MarkerDetector myDetector;
    // liste de marqueurs : sera remplie par ArUco
    vector <Marker> markers ;
    // detection
    myDetector.detect(image, markers);
    // on affiche les résultats de la détection sur une image
    for (unsigned int i=0; i <markers.size(); i++) {
        cout << markers[i];
        markers[i].draw(image, Scalar(0, 0, 255), 2);
    }
    imshow("Affichage",image);
    int key=0;
    while ((key!=ESC_KEY_VM) && (key!=Q_KEY_VM)) {
        key = waitKey(1);
    }
    destroyAllWindows();

    return 0;
}