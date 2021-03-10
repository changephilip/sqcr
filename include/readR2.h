#include "../include/readR1.h"


typedef struct
{
        //std::string pair2;
        uint32_t seqId;
        std::string seq;
        std::string q;
} rSecondRead;

class rSecond {
 public:
        std::vector<rSecondRead> reads;
        
        rSecond(const std::string r2gz, const rFirst & rfirst);
};

rSecond::rSecond(const std::string r2gz, const rFirst & rfirst){
        gzFile fp;
        kseq_t *seq;
        int l;
        fp = gzopen(r2gz.c_str(),"r");
        seq = kseq_init(fp);
        uint32_t readId = 0;

        while (( l = kseq_read(seq)) >=0){
                std::string thisName = seq->name.s;
                if (rfirst.readsNameTable.find(thisName)!= rfirst.readsNameTable.end()){
                        rSecondRead tmp;
                        tmp.seq = seq->seq.s;
                        tmp.seqId = readId;
                        tmp.q = seq->qual.s;
                        //assert(rfirst.readsNameTable.find(thisName).second);
                        reads.push_back(tmp);
                }
                readId ++;
        }
}
