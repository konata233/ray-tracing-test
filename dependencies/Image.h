//
// Created on 2024/9/21.
//

#ifndef RAY_TRACING_IMAGE_H
#define RAY_TRACING_IMAGE_H

#include "third-party/stb_image_write.h"

class ImageDevice {
public:
    int write_to_file(char* filename);

    void set_buffer(unsigned char* buf);

    ImageDevice(unsigned char* buf, int ch, int width, int height);

    ImageDevice();

protected:
    unsigned char* buffer = nullptr;

    int channels = 0;
    int width = 0;
    int height = 0;
};


#endif //RAY_TRACING_IMAGE_H
