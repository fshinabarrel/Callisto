/* generated thread source file - do not edit */
#include "MotorC.h"

TX_THREAD MotorC;
void MotorC_create(void);
static void MotorC_func(ULONG thread_input);
static uint8_t MotorC_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.MotorC") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void MotorC_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&MotorC, (CHAR *) "MotorC", MotorC_func, (ULONG) NULL, &MotorC_stack, 1024, 1, 1, 1,
                            TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&MotorC, 0);
    }
}

static void MotorC_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    MotorC_entry ();
}
