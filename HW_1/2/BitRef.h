#pragma once
#include<cstdint>


class BitRef
{
	uint8_t& bucket;
	unsigned indexInBucket;
public:
	BitRef(uint8_t& bucket, unsigned indexInBucket);
	operator bool() const;
	BitRef operator=(bool val);
};

