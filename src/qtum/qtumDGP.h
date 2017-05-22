#include "qtumstate.h"

static const dev::Address DGPCONTRACT1 = dev::Address("0000000000000000000000000000000000000080"); // gasSchedule
static const dev::Address DGPCONTRACT2 = dev::Address("0000000000000000000000000000000000000081"); // blockSize
static const dev::Address DGPCONTRACT3 = dev::Address("0000000000000000000000000000000000000082");
static const dev::Address DGPCONTRACT4 = dev::Address("0000000000000000000000000000000000000083");
static const dev::Address DGPCONTRACT5 = dev::Address("0000000000000000000000000000000000000084");

class QtumDGP {
    
public:

    dev::eth::EVMSchedule getGasSchedule(QtumState* state, unsigned int blockHeight);

    uint32_t getBlockSize(QtumState* state, unsigned int blockHeight);

private:

    void initStorageDGP(QtumState* state, const dev::Address& addr);

    void initStorageTemplate(QtumState* state, const dev::Address& addr);

    void createParamsInstance();

    dev::Address getAddressForBlock(unsigned int blockHeight);

    void parseStorageScheduleContract(std::vector<uint32_t>& uint32Values);

    void parseStorageBlockSizeContract(uint32_t& blockSize);

    dev::eth::EVMSchedule createEVMSchedule();

    void clear();

    dev::Address templateContract;

    std::map<dev::h256, std::pair<dev::u256, dev::u256>> storageDGP;

    std::map<dev::h256, std::pair<dev::u256, dev::u256>> storageTemplate;

    std::vector<std::pair<unsigned int, dev::Address>> paramsInstance;

};
