function [index,array] = partition(array,low,high)
%Partitions arrays for quickSort algorithm.

pivot = array(high);

index = low;

for j = low:high-1
    if array(j) <= pivot
        k = array(index);
        array(index) = array(j);
        array(j) = k;
        index = index+1;
    end
end

l = array(index);
array(index) = array(high);
array(high) = l;

end
