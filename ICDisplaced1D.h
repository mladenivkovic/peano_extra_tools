#pragma once

#include <string>

namespace initialConditions {
  namespace oneDim {

    class ICDisplaced{

public:
      std::string name = "1D Randomly Displaced";

      int sampleSize = 60;

      double coords[60][3] = {
        { 7.03882719e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.12712936e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.21319780e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.33365045e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.40344519e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.50572245e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.64830995e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.78744326e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.87532033e-02, 0.00000000e+00, 0.00000000e+00 },
        { 7.97518003e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.04076891e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.10829230e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.26820002e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.38400879e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.49452521e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.55437080e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.64948152e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.74494041e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.88080794e-02, 0.00000000e+00, 0.00000000e+00 },
        { 8.90660682e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.01246320e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.17680005e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.20358857e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.32702810e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.40029312e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.51305671e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.62944654e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.79052240e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.83739558e-02, 0.00000000e+00, 0.00000000e+00 },
        { 9.90365706e-02, 0.00000000e+00, 0.00000000e+00 },
        { 1.00376267e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.01887584e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.02969679e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.03879078e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.04651158e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.05664768e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.06550893e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.07224049e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.08438208e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.09966688e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.10061380e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.11213855e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.12935327e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.13752495e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.14602052e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.15897043e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.16727806e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.17080758e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.18368713e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.19764904e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.20767303e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.21534022e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.22260086e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.23175237e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.24163232e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.25906220e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.26862974e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.27693302e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.28435352e-01, 0.00000000e+00, 0.00000000e+00 },
        { 1.29914934e-01, 0.00000000e+00, 0.00000000e+00 }
      };


      int ids[60] = {
        71,
        72,
        73,
        74,
        75,
        76,
        77,
        78,
        79,
        80,
        81,
        82,
        83,
        84,
        85,
        86,
        87,
        88,
        89,
        90,
        91,
        92,
        93,
        94,
        95,
        96,
        97,
        98,
        99,
        100,
        101,
        102,
        103,
        104,
        105,
        106,
        107,
        108,
        109,
        110,
        111,
        112,
        113,
        114,
        115,
        116,
        117,
        118,
        119,
        120,
        121,
        122,
        123,
        124,
        125,
        126,
        127,
        128,
        129,
        130
      };


      double sml_init[60] = {
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026,
        0.0020000000949949026
      };
      double sml_solution[60] = {
        0.002403502699318757,
        0.002462803789708361,
        0.0024807501026502064,
        0.0025017548532317814,
        0.002601733005488877,
        0.0028847520667149972,
        0.003064259753646597,
        0.0027703482933286866,
        0.002432881653698131,
        0.002190002111295459,
        0.002272752963483136,
        0.0025470276091653387,
        0.002908532867823539,
        0.0027241844506600025,
        0.002381151622129377,
        0.0023064802731903224,
        0.0023868752861077557,
        0.0024383306209632247,
        0.0023595629568538092,
        0.00237295557235216,
        0.002532875905109197,
        0.0024791003602885556,
        0.0024317473111651186,
        0.002383648666612447,
        0.002524341551307876,
        0.0028147920363735313,
        0.002883943620964333,
        0.0024855257856659196,
        0.00237495709050998,
        0.002486775460844478,
        0.002948721015748113,
        0.0029592516235139275,
        0.002626667052419188,
        0.0023821175278667976,
        0.0023099572673767285,
        0.0022876959234350808,
        0.0023457205865171395,
        0.002483319346188572,
        0.0026167593016320967,
        0.002512225872935074,
        0.0025172199112823545,
        0.002769461163684553,
        0.002842197451320311,
        0.0026769118846074226,
        0.002516449599621497,
        0.002320065955373657,
        0.002235081554048665,
        0.002305591873405831,
        0.002711688402655394,
        0.002695351431920311,
        0.0023705221162673793,
        0.002181885635601591,
        0.002217057746352477,
        0.0025326081742278114,
        0.002906575440914986,
        0.0028990899892718355,
        0.0025900261156201728,
        0.002461978317100849,
        0.002520110253771574,
        0.002496991712207332
      };

    }; // end class
  } // namespace oneDim
} // namespace initialConditions