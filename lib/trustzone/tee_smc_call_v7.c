// TODO: will try to re-construct this function to be similar to
// "optee_smccc_smc" in u-boot23
// -- a wrapper to "arm_smccc_smc"

#include "uboot_sec_drv.h"

// including for asm linkage. (hint: need smccc-call.S built/linked
// for arm_smccc_smc to be embedded )
#include <linux/arm-smccc.h>

// hint: we need smccc-call.S to exist for this
// it is what calls/references "arm_smccc_smc" function
void tee_smc_call(struct smc_param *param)
{
	/* this should (hopefully) update param struct params a0-a3,
	 using the board/chip-specific parameters from
	 uboot_sec_drv.h passed into the registers a0-a7
	 which will then be returned by
	 tee_common_call outside this scope */
	arm_smccc_smc(param->a0, param->a1, param->a2, param->a3,
                param->a4, param->a5, param->a6, param->a7, NULL);
}
