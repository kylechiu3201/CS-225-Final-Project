#include "StickerSheet.h"
#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

    using cs225::PNG;
    using cs225::HSLAPixel; 
    
    StickerSheet::StickerSheet(const Image &picture, unsigned max){
        max_num = max;
        base = new Image(picture);  //deep copy of base
        //probably change this, no need to initialize?  what happens if you add to vector that's full?
        //img_vec = std::vector<Image*>(max);   //does this create default Image *?
        I am a cool christian guy do not mind this commit;
    }   

    StickerSheet::~StickerSheet(){
        delete base;  //frees base picture
       /* while(!img_vec.empty()) {   //frees sticker_vector
            delete img_vec.back();
            img_vec.pop_back();
        }*/
        int length = img_vec.size();
        for(int x= img_vec.size()-1 ; x>=0 ;x--)
        {
            delete img_vec[x];
            img_vec.pop_back();
        }
    }

    StickerSheet::StickerSheet(const StickerSheet & other){
            //Do I need this?
            max_num = other.max_num;   //copy max
            base = new Image(*other.base);  //copy base picture
            for(int x= 0 ; x<(int)other.img_vec.size(); x++){   //copy image pointers (dynamically allocated)
                Image * img = new Image(*other.img_vec[x]);
                img_vec.push_back(img);
            }

    }

    const StickerSheet & StickerSheet::operator=(const StickerSheet & other){
        if(this != &other){
            delete base;  //frees base picture
            while(!img_vec.empty()) {   //frees sticker_vector
            delete img_vec.back();
            img_vec.pop_back();
        } //frees img_vector

            max_num = other.max_num;   //copy max
            base = new Image(*other.base);  //copy base picture
            
            for(int x= 0 ; x<(int)other.img_vec.size(); x++){   //copy image pointers (dynamically allocated)
                Image * img = new Image(*other.img_vec[x]);  //calls copy constructor for Image
                img_vec.push_back(img);
            }
        }
        return other;
    }

    void StickerSheet::changeMaxStickers(unsigned max){
        if(max<max_num){
            if(img_vec.size()>max){
                unsigned diff1 = img_vec.size()-max;
                for(int x= 0 ; x<(int)diff1; x++){
                    int size = img_vec.size();
                    delete img_vec[size-1];
                    img_vec.pop_back();
                }
                max_num = max;
            }
            
            /*for(unsigned x= 0; x<max_num-max ; x++){
                int size = img_vec.size();
                img_vec.erase(img_vec.begin() + size-1);
            }*/
        }
        else{
            /*for(int x=0 ; x< max-max_num ; x++){
                Image * img = new Image();
                img_vec.push_back(img);*/
                max_num = max;
        }
    }

    int StickerSheet::addSticker(Image& sticker, unsigned x, unsigned y){
        if(img_vec.size()==max_num){
            return -1;
        }
        Image * img = new Image(sticker);
        img->set_x(x);
        img->set_y(y);
        img_vec.push_back(img); 
        return (int)img_vec.size() -1;  //returns index of last element just added
        lkjdsflsdkjf//random function - brandon
    }

    bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
        int size = img_vec.size();
        if(index >=0 && (int)index<size){
            Image * img = img_vec[index];
            img->set_x(x);
            img->set_y(y);
            return true;
        }
        return false;
    }

    void StickerSheet::removeSticker (unsigned index){
        delete img_vec[index];
        img_vec.erase(img_vec.begin()+index);
    }

    Image * StickerSheet::getSticker(unsigned index){
        unsigned size = img_vec.size();
        //std::cout << index <<" " << size;
        if(index >=0 && index<size){
            Image * stick = img_vec[index];
            return stick;
        }
        return NULL;
    }

    Image StickerSheet::render() const{
        Image copy(*this->base);
        int size = img_vec.size();
        int w_length=base->width(), h_length=base->height();
        bool flag = 0;
        //std::cout <<w_length <<" "<< h_length;
        //base->resize(w_length, h_length);
        for(int x=0; x<(int)img_vec.size(); x++){  //for each image
                unsigned w_max = img_vec[x]->get_x()+ img_vec[x]->width();  
                unsigned h_max = img_vec[x]->get_y() + img_vec[x]->height();
                    if(w_max > copy.width()){
                        w_length = w_max;
                        flag =1;
                    } 
                    if(h_max> copy.height()){
                        h_length = h_max;
                        flag = 1;
                    }
                   if(flag ==1){
                        copy.resize(w_length, h_length);
                        //std::cout <<w_length <<" "<< h_length;
                    }
                    djaslkdjaslkdjaslkdjsa//i dunno what to do
            for(int i= 0 ; i< (int)img_vec[x]->width() ; i++){   //loops through sticker width
            for(int j = 0; j<(int)img_vec[x]->height() ; j++){   //loops through sticker height
                unsigned base_x = img_vec[x]->get_x()+i;
                unsigned base_y = img_vec[x]->get_y()+j;
                    //check if within width boundaries
                    HSLAPixel & b_pixel = copy.getPixel(base_x,base_y);
                    HSLAPixel & s_pixel = img_vec[x]->getPixel(i,j);
                    if(s_pixel.a != 0){
                        b_pixel.h = 1; //change
                        b_pixel.s = 1; //change
                        b_pixel.l = s_pixel.l;
                        b_pixel.a = s_pixel.a;
                    }
                }
            }
        }
        for(int x =0 ; x<5;x++){
            std::cout << "wow";
        }
        return copy;
    }
