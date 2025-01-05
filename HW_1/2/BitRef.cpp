#include "BitRef.h"

static constexpr uint8_t createMask(uint8_t ind) {
	return 1 << ind;
}

BitRef::BitRef(uint8_t& bucket, unsigned indexInBucket) : bucket(bucket), indexInBucket(indexInBucket) {}

BitRef::operator bool() const
{
    return (bucket & createMask(indexInBucket))!=0;
}

BitRef BitRef::operator=(bool val)
{
	if (val)
		bucket |= createMask(indexInBucket);  
	else
		bucket &= ~createMask(indexInBucket); 
	return *this;
}
