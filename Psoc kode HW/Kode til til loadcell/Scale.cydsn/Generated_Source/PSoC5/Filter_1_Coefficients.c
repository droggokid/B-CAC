#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is: Biquad
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelABiquadCoefficients Filter_1_ChannelABiquadCoefficients

/* Number of Biquad sections are: 8 */

const uint8 CYCODE Filter_1_ChannelABiquadCoefficients[Filter_1_BIQUAD_A_SIZE] = 
{
 /* Coefficients of Section 0 */
 0x05u, 0x00u, 0x00u, 0x00u, /* Section(0)_A0, 1.19209289550781E-06 */

 0x0Au, 0x00u, 0x00u, 0x00u, /* Section(0)_A1, 2.38418579101563E-06 */

 0x05u, 0x00u, 0x00u, 0x00u, /* Section(0)_A2, 1.19209289550781E-06 */

 0xB7u, 0x99u, 0x7Fu, 0x00u, /* Section(0)_B1, -1.99375700950623 */

 0x21u, 0x66u, 0xC0u, 0x00u, /* Section(0)_B2, 0.99376654624939 */

 /* Coefficients of Section 1 */
 0x14u, 0x00u, 0x00u, 0x00u, /* Section(1)_A0, 4.76837158203125E-06 */

 0x27u, 0x00u, 0x00u, 0x00u, /* Section(1)_A1, 9.29832458496094E-06 */

 0x14u, 0x00u, 0x00u, 0x00u, /* Section(1)_A2, 4.76837158203125E-06 */

 0xA0u, 0x9Du, 0x7Fu, 0x00u, /* Section(1)_B1, -1.99399566650391 */

 0x37u, 0x62u, 0xC0u, 0x00u, /* Section(1)_B2, 0.994005441665649 */

 /* Coefficients of Section 2 */
 0x12u, 0x00u, 0x00u, 0x00u, /* Section(2)_A0, 4.29153442382813E-06 */

 0x24u, 0x00u, 0x00u, 0x00u, /* Section(2)_A1, 8.58306884765625E-06 */

 0x12u, 0x00u, 0x00u, 0x00u, /* Section(2)_A2, 4.29153442382813E-06 */

 0x4Du, 0xA5u, 0x7Fu, 0x00u, /* Section(2)_B1, -1.99446415901184 */

 0x8Au, 0x5Au, 0xC0u, 0x00u, /* Section(2)_B2, 0.994473934173584 */

 /* Coefficients of Section 3 */
 0x10u, 0x00u, 0x00u, 0x00u, /* Section(3)_A0, 3.814697265625E-06 */

 0x20u, 0x00u, 0x00u, 0x00u, /* Section(3)_A1, 7.62939453125E-06 */

 0x10u, 0x00u, 0x00u, 0x00u, /* Section(3)_A2, 3.814697265625E-06 */

 0x75u, 0xB0u, 0x7Fu, 0x00u, /* Section(3)_B1, -1.99514508247375 */

 0x62u, 0x4Fu, 0xC0u, 0x00u, /* Section(3)_B2, 0.995154857635498 */

 /* Coefficients of Section 4 */
 0x0Du, 0x00u, 0x00u, 0x00u, /* Section(4)_A0, 3.09944152832031E-06 */

 0x1Au, 0x00u, 0x00u, 0x00u, /* Section(4)_A1, 6.19888305664063E-06 */

 0x0Du, 0x00u, 0x00u, 0x00u, /* Section(4)_A2, 3.09944152832031E-06 */

 0xAAu, 0xBEu, 0x7Fu, 0x00u, /* Section(4)_B1, -1.99601221084595 */

 0x2Du, 0x41u, 0xC0u, 0x00u, /* Section(4)_B2, 0.99602198600769 */

 /* Coefficients of Section 5 */
 0x0Au, 0x00u, 0x00u, 0x00u, /* Section(5)_A0, 2.38418579101563E-06 */

 0x13u, 0x00u, 0x00u, 0x00u, /* Section(5)_A1, 4.52995300292969E-06 */

 0x0Au, 0x00u, 0x00u, 0x00u, /* Section(5)_A2, 2.38418579101563E-06 */

 0x63u, 0xCFu, 0x7Fu, 0x00u, /* Section(5)_B1, -1.99703288078308 */

 0x75u, 0x30u, 0xC0u, 0x00u, /* Section(5)_B2, 0.997042417526245 */

 /* Coefficients of Section 6 */
 0x06u, 0x00u, 0x00u, 0x00u, /* Section(6)_A0, 1.43051147460938E-06 */

 0x0Cu, 0x00u, 0x00u, 0x00u, /* Section(6)_A1, 2.86102294921875E-06 */

 0x06u, 0x00u, 0x00u, 0x00u, /* Section(6)_A2, 1.43051147460938E-06 */

 0xFCu, 0xE1u, 0x7Fu, 0x00u, /* Section(6)_B1, -1.99816799163818 */

 0xDBu, 0x1Du, 0xC0u, 0x00u, /* Section(6)_B2, 0.998177766799927 */

 /* Coefficients of Section 7 */
 0x08u, 0x00u, 0x00u, 0x00u, /* Section(7)_A0, 1.9073486328125E-06 */

 0x10u, 0x00u, 0x00u, 0x00u, /* Section(7)_A1, 3.814697265625E-06 */

 0x08u, 0x00u, 0x00u, 0x00u, /* Section(7)_A2, 1.9073486328125E-06 */

 0xC1u, 0xF5u, 0x7Fu, 0x00u, /* Section(7)_B1, -1.99937462806702 */

 0x16u, 0x0Au, 0xC0u, 0x00u, /* Section(7)_B2, 0.99938440322876 */
};

