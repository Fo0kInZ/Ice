//
//  Terra.cpp
//  Entropy

#include "Terra.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

struct info
{
    char Name;
};
struct vector {
    float x,y,z;
};
struct body {
    vector location;
    vector direction;
    float mass;
    info meta;
};
struct AU {
    //  149.60×109 m
    body objects[64];
};
struct MetaAU {
    AU units[1024];
};
MetaAU existence;

bool loadMetaAU(void)
{
/*
    FILE *data;
    data = fopen("/Users/snow/Downloads/MetaAU.txt", "w");

    CFPropertyListRef propertyList;
    CFStringRef       errorString;
    CFDataRef         resourceData;
    Boolean           status;
    SInt32            errorCode;

    CFURLRef fileURL = CFURLCreateWithString(NULL, "/Users/snow/Downloads/MetaAU.txt", NULL);

    status = CFURLCreateDataAndPropertiesFromResource(
                                                      kCFAllocatorDefault,
                                                      fileURL,
                                                      &resourceData,            // place to put file data
                                                      NULL,
                                                      NULL,
                                                      &errorCode);
    
    // Reconstitute the dictionary using the XML data.
    propertyList = CFPropertyListCreateFromXMLData( kCFAllocatorDefault,
                                                   resourceData,
                                                   kCFPropertyListImmutable,
                                                   &errorString);
    
    if (resourceData) {
        CFRelease( resourceData );
    }
        else {
            CFRelease( errorString );
        }
        return propertyList;
*/
}

bool saveMetaAU(void)
{
    
}

bool initNewMetaAU(void)
{
    MetaAU space;
    space.units[1].objects[1].location.x = 1;
    space.units[1].objects[1].location.y = 1;
    space.units[1].objects[1].location.z = 1;
    
    space.units[1].objects[2].location.x = 10;
    space.units[1].objects[2].location.y = 10;
    space.units[1].objects[2].location.z = 10;
    
    space.units[1].objects[3].location.x = 30;
    space.units[1].objects[3].location.y = 30;
    space.units[1].objects[3].location.z = 30;
    
    existence = space;
}
void iterate(void)
{
    double r;
    double N;
    for (int x; x <= sizeof(existence.units)/sizeof(AU) ; x++) {
        for (int y; y <= sizeof(existence.units[x].objects)/sizeof(body); y++) {
            for (int z; z <= sizeof(existence.units)/sizeof(AU) ; z++) {
                for (int w; w <= sizeof(existence.units[x].objects)/sizeof(body); w++) {
                    
                    r = abs(pow(pow(existence.units[x].objects[y].location.y - existence.units[z].objects[w].location.y, 2)+pow(existence.units[x].objects[y].location.z - existence.units[z].objects[w].location.z, 2)+pow(existence.units[x].objects[y].location.x - existence.units[z].objects[w].location.x, 2),.5));
                    
                    N=existence.units[x].objects[y].mass*existence.units[z].objects[w].mass/pow(r, 2);
                    N=N*kG;
                    printf("Distance:%f, Newtons:%f\n",r,N);
                    
                    //Add vectors
                }
            }
        }
    }
}