version=`astyle --version 2> /dev/null`
if test "x$version" != "x"; then
	ASTYLE=astyle
else
	version=`Tools/AStyle/astyle --version 2> /dev/null`
	if test "x$version" != "x"; then
		echo "git pre-receive hook: Did not find astyle, please install it before continuing."
		exit 1
	else
		ASTYLE=Tools/AStyle/astyle
	fi
fi
echo `$ASTYLE --version`

case `$ASTYLE --version 2> /dev/null` in
  Artistic*)
      ;;
  default)
      echo "git pre-commit hook: Did not find astyle, please install it before continuing."
      exit 1
      ;;
esac
ASTYLE_PARAMETERS=" \
    --indent=spaces=4 \
    --indent-switches \
    --indent-namespaces \
    --indent-preprocessor \
    --indent-labels \
    --unpad-paren \
    --keep-one-line-blocks \
    --keep-one-line-statements \
    --lineend=linux \
    --suffix=none"
FILES=`ls --color=never > Tools/AStyle/files.txt`
FILES_CPP=`sed -n -e '/^.*\\.cpp\$/p' Tools/AStyle/files.txt`
$ASTYLE ${ASTYLE_PARAMETERS} $FILES_CPP