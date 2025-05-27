#include<iostream>
#include<string>
#include<vector>
using namespace std;
//����bmp�ļ�ͷ�Ľṹ��
struct bmpHead
{
    unsigned short fileType;
    unsigned int fileSize;
    unsigned short reserved;
    unsigned int pixelDataOffset;
};
//����bmp������Ϣͷ
struct bmpInformationHead
{
    unsigned int headerSize;
    unsigned int imageWidth;
    unsigned int imageHeight;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPixelPerMeter;
    unsigned int yPixelPerMeter;
    unsigned int totalColors;
    unsigned int importantColors;
};
//bmp������������ݾ���
class Matrix
{
public:
    Matrix(int width, int height, int channel);
    void getShape(int(*p)[3]);
private:
    int shape[3] = { 0,0,0 };//�������״Ĭ�����֧����ά
    int size;//������Ԫ�صĸ���
    vector<int> piexlMatrix;
};
void Matrix::getShape(int(*p)[3])
{
    *(p[0]) = this->shape[0];
    *(p[0]+1) = this->shape[1];
    *(p[0]+2) = this->shape[2];
}
Matrix::Matrix(int width, int height, int channel)
{
    this->shape[0] = width;
    this->shape[1] = height;
    this->shape[2] = channel;
}
int main()
{
    Matrix matrix = Matrix(32, 32, 3);
    int shape[3];
    matrix.getShape(&shape);
    for (int i = 0; i < 3; i++) {
        cout << shape[i] << endl;
    }
    return 0;
}
