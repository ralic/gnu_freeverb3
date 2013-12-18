class _FV3_(earlyref) : public _FV3_(revbase)
{
public:
  _FV3_(earlyref)() throw(std::bad_alloc);
  virtual _FV3_(~earlyref)();

  virtual void mute();
  virtual void processreplace(_fv3_float_t *inputL, _fv3_float_t *inputR, _fv3_float_t *outputL, _fv3_float_t *outputR, long numsamples)
    throw(std::bad_alloc);
  
  void loadPresetReflection(long program);
  long getCurrentPreset();
  void loadUserReflection(const _fv3_float_t * delayL, const _fv3_float_t * gainL,
			  const _fv3_float_t * delayDiff, const _fv3_float_t * gainDiff, long size)
    throw(std::bad_alloc);
  void unloadReflection();
  
  void         setLRDelay(_fv3_float_t value_ms);
  _fv3_float_t getLRDelay();
  void         setLRCrossApFreq(_fv3_float_t fc, _fv3_float_t bw);
  _fv3_float_t getLRCrossApFreq();
  void         setDiffusionApFreq(_fv3_float_t fc, _fv3_float_t bw);
  _fv3_float_t getDiffusionApFreq();

  void setoutputlpf(_fv3_float_t value);
  _fv3_float_t getoutputlpf();
  void setoutputhpf(_fv3_float_t value);
  _fv3_float_t getoutputhpf();
  
 protected:
  _FV3_(earlyref)(const _FV3_(earlyref)& x);
  _FV3_(earlyref)& operator=(const _FV3_(earlyref)& x);
  void loadReflection(const _fv3_float_t * delayL, const _fv3_float_t * gainL, const _fv3_float_t * delayDiff, const _fv3_float_t * gainDiff, long size)
    throw(std::bad_alloc);
  virtual void setFsFactors();
  
  _FV3_(delayline) delayLineL, delayLineR;
  _FV3_(delay) delayLtoR, delayRtoL;
  _FV3_(biquad) allpassXL, allpassL2, allpassXR, allpassR2;
  _FV3_(iir_1st) out1_lpf, out2_lpf, out1_hpf, out2_hpf;
  long currentPreset, tapLength, lrDelay;
  _fv3_float_t lrCrossApFq, lrCrossApBw, diffApFq, diffApBw, outputlpf, outputhpf;
  _fv3_float_t *gainTableL, *gainTableR, *delayTableL, *delayTableR;

  const static long preset0_size;
  const static _fv3_float_t preset0_delayL[], preset0_delayDiff[], preset0_gainL[], preset0_gainDiff[];
  const static long preset1_size;
  const static _fv3_float_t preset1_delayL[], preset1_delayDiff[], preset1_gainL[], preset1_gainDiff[];
  const static long preset2_size;
  const static _fv3_float_t preset2_delayL[], preset2_delayDiff[], preset2_gainL[], preset2_gainDiff[];
};