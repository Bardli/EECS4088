        .cdecls "pruTest.c"
        .clink
                .global start
        .asg 0x00000000 CONTROL_FLAG ; Address of the control flag
        .asg 0x00000004 COUNT_STORAGE ; Address to store the count
        .asg 1 TIMER_ACTIVE            ; Value indicating the timer should be running
        .asg "5000" DELAY_ITERATIONS ; 5000 cycle for 1 us
; Main loop

START:
        ; Check the control flag to see if the timer should be running
        LBBO r1, r0, CONTROL_FLAG, 4 ; Load the control flag into r1 from address CONTROL_FLAG
        ;CMP r1, TIMER_ACTIVE        ; Compare control flag with TIMER_ACTIVE
        QBNE STOP_TIMER, r1, TIMER_ACTIVE ; If not equal to TIMER_ACTIVE, jump to STOP_TIMER

        ;Timer is active, increment the counter
        LBBO r0, r0, COUNT_STORAGE, 4; Load current count
        ADD r0, r0, 1                 ; Increment the count
        SBBO r0, r0, COUNT_STORAGE, 4 ; Store back the updated count
        ; preventing too much write we need a delay
        LDI32 r2, DELAY_ITERATIONS  ; Load the number of delay iterations into r2
        ; Implement some delay if needed, then loop
        ;JMP START                     ; Jump back to start to continually check the flag and increment
DELAY_LOOP:
        SUB r2, r2, 1             ; Decrement the delay counter
        QBNE DELAY_LOOP, r2, 0    ; Continue looping until the counter reaches zero

        ; Continue with the rest of the program
        JMP START                 ; Loop back to the beginning
STOP_TIMER:
        LBBO r1, r0, CONTROL_FLAG, 4 ; Load the control flag into r1 from address CONTROL_FLAG
        QBEQ START, r1, TIMER_ACTIVE
        JMP STOP_TIMER

