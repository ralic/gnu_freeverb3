class _FV3_(utils)
{
 public:
  static _fv3_float_t dB2R(_fv3_float_t dB);
  static _fv3_float_t R2dB(_fv3_float_t real);
  static long ms2sample(_fv3_float_t msec, long fs);
  static long ms2sample(_fv3_float_t msec, _fv3_float_t fs);
  static void mute(_fv3_float_t * f, long t);
  static long checkPow2(long i);
  static bool isPrime(long number);
  static void * aligned_malloc(size_t size, size_t align_size);
  static void   aligned_free(void *ptr);
  static uint16_t getX87CW();
  static void     setX87CW(uint16_t cw);
  static uint32_t getMXCSR();
  static uint32_t getMXCSR_MASK();
  static void     setMXCSR(uint32_t mxcsr);
  static void cpuid(uint32_t op, uint32_t *_eax, uint32_t *_ebx, uint32_t *_ecx, uint32_t *_edx);
  static void XGETBV(uint32_t op, uint32_t * _eax, uint32_t *_edx);
  static uint32_t getSIMDFlag();
};
