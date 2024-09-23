//
// Created on 2024/9/21.
//
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "Image.h"

ImageDevice::ImageDevice() = default;

ImageDevice::ImageDevice(unsigned char* buf, int ch, int width, int height) {
    this->buffer = buf;
    this->channels = ch;
    this->width = width;
    this->height = height;
}

void ImageDevice::set_buffer(unsigned char* buf) {
    this->buffer = buf;
}

int ImageDevice::write_to_file(char* filename) {
    stbi_flip_vertically_on_write(true);
    return stbi_write_png(filename, width, height, channels, this->buffer, 0);
}
