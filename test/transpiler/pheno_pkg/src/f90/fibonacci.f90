MODULE Fibonacci_mod
    USE list_sub
    IMPLICIT NONE
CONTAINS
    SUBROUTINE fibonacci_(n, &
        result)
        INTEGER, INTENT(OUT) :: result
        INTEGER:: b
        INTEGER:: temp
        INTEGER:: i
        INTEGER, INTENT(IN) :: n
        !- Description:
    !            - Model Name: fibonacci function
    !            - Author: Pierre Martre
    !            - Reference:  to write in package
    !            - Institution: INRA Montpellier
    !            - Abstract: see documentation
        !- inputs:
    !            - name: n
    !                          - datatype : INT
    !                          - description : argument
    !                          - inputtype : variable
        !- outputs:
    !            - name: result
    !                          - datatype : INT
    !                          - description :  fibonacci number 
        result = 0
        b = 1
        DO i = 0 + 1  , n , 1
            temp = result
            result = b
            b = temp + b
        END DO
    END SUBROUTINE fibonacci_
END MODULE