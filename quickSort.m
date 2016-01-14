function [sortedArray] = quickSort(array,low,high)
%Sorts an array using quicksort.

if nargin < 3
    array = [2,4,5,9,7,6,1,8,3];
    low = 1;
    high = length(array);
end

if low < high
    
    [pivot,array] = partition(array,low,high);
    
    quickSort(array,low,pivot-1);
    quickSort(array,pivot+1,high);
end

end


