#ifndef __MODEL_PROP_HPP__
#define __MODEL_PROP_HPP__

//datasets path
#define DATASETS "/home/archw/packs/imgProcess/datasets"
#define AZ_TR "/dataset_az_tr"
#define AZ_EN "/dataset_az_en"
#define DATASET_AB_POSXY "/home/archw/packs/imgProcess/datasets/dataset_ab_posxy"

//model prop
#define OUTPUT_LAYER 26
#define HIDDEN_LAYER 256    //16_X 32_t 64_t 128_O 
#define LEARNING_RATE 0.01  //0.1_O 0.25_XO 0.01_t 0.05_t
#define TOTAL_EPOCH_TRAIN 6000
#define PRINT_COUNT_FIT 100
#define THREAD_COUNT 16     //fizikselcore x 2 = total thread

#define THRESHOLD_DATASET_USER_PARAMS 128
#define THRESHOLD_READ false //kullanici dosyasida esiklenmeli egitim setini esikliyor

#define NORMALIZE_READ true
#define NORMALIZE_OP NORMALIZE_READ   


#define GRID_SIZE 28
#define SEGMENT_THRESHOLD 0.80


#endif //__MODEL_PROP_HPP__
/*
(1)
HIDDEN_LAYER        128
LEARNING_RATE       0.01
TOTAL_EPOCH_TRAIN   1000
THRESHOLD_READ      false
NORMALIZE_READ      true
CIKMASI GEREKEN     helloworld
SONUC               bbiibmbfib
AGIRLIKLANDIRMA : RandomMath::getRandom() * sqrt(1.0 / inputLayerSize);

(2)
HIDDEN_LAYER        64
LEARNING_RATE       0.1
TOTAL_EPOCH_TRAIN   1000
THRESHOLD_READ      false
NORMALIZE_READ      true
CIKMASI GEREKEN     helloworld
SONUC               kfiiieifii
AGIRLIKLANDIRMA : RandomMath::getRandom() * sqrt(1.0 / inputLayerSize);

(3)
HIDDEN_LAYER        128
LEARNING_RATE       0.01
TOTAL_EPOCH_TRAIN   2500
THRESHOLD_READ      false
NORMALIZE_READ      true
CIKMASI GEREKEN     helloworld
SONUC               bbiibmbfib
AGIRLIKLANDIRMA : RandomMath::getRandom() * sqrt(1.0 / inputLayerSize);

(4)
HIDDEN_LAYER        256
LEARNING_RATE       0.1
TOTAL_EPOCH_TRAIN   1000
THRESHOLD_READ      false
NORMALIZE_READ      true
CIKMASI GEREKEN     helloworld
SONUC               rfzzbebfzb
AGIRLIKLANDIRMA : RandomMath::getRandom() * sqrt(1.0 / inputLayerSize);

(5)
HIDDEN_LAYER        256
LEARNING_RATE       0.01
TOTAL_EPOCH_TRAIN   2500
THRESHOLD_READ      false
NORMALIZE_READ      true
CIKMASI GEREKEN     helloworld
SONUC               hdttbpbftk
AGIRLIKLANDIRMA : RandomMath::getRandom()

(5)
HIDDEN_LAYER        256
LEARNING_RATE       0.01
TOTAL_EPOCH_TRAIN   5000
THRESHOLD_READ      false
NORMALIZE_READ      true
CIKMASI GEREKEN     helloworld
SONUC               bbkkbqbbkk
AGIRLIKLANDIRMA : RandomMath::getRandom()

(6)
HIDDEN_LAYER        256
LEARNING_RATE       0.01
TOTAL_EPOCH_TRAIN   2500
THRESHOLD_READ      false
NORMALIZE_READ      true
CIKMASI GEREKEN     helloworld
SONUC               hkqqbgbfqd
AGIRLIKLANDIRMA : RandomMath::getRandom()


(6)
HIDDEN_LAYER        256
LEARNING_RATE       0.01
TOTAL_EPOCH_TRAIN   1000
THRESHOLD_READ      false
NORMALIZE_READ      true
CIKMASI GEREKEN     helloworld
SONUC               tbggbdbfgb
AGIRLIKLANDIRMA : RandomMath::getRandom()


*/
