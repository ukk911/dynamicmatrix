#include "Test.h"
#include "Matrix.h"

int main() {
    testMatrixDefaultConstructor();
    testMatrixParameterizedConstructor();
    testMatrixCopyConstructor();
    testMatrixRandomFill();
    testMatrixReplace();
    testMatrixCallOperator();
    testMatrixSearch();

    testMatrixAssignmentOperator();
    testMatrixAdditionOperator();
    testMatrixSubtractionOperator();
    testMatrixIndexingOperator();

    testMatrixInputOperator();
    testMatrixOutputOperator();
   
    testMatrixSaveToBinaryFile();
    testMatrixLoadFromBinaryFile();

    
    testSingleMatrix();
    testTriangularMatrix();

    testCyclicLinkedListAdd();
    testCyclicLinkedListRemove();
    testCyclicLinkedListInsertAt();
    testCyclicLinkedListRemoveAt();
    testCyclicLinkedListSearch();
    testCyclicLinkedListPrintList();

    return 0;
}