echo "In each line we are shifting one parameter forward:"

echo "arg1=$1, arg2=$2, arg3=$3"
shift

echo "arg2=$1, arg3=$2, arg4=$3"
shift

echo "arg3=$1, arg4=$2, arg5=$3"
shift

echo "arg4=$1, arg5=$2, arg6=$3"
shift
