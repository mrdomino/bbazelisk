all: bbazelisk.com

bbazelisk.com: bbazelisk bazelisk-darwin-arm64
	cp bbazelisk bbazelisk.com
	zip -0 bbazelisk.com bazelisk-darwin-arm64

bbazelisk: bbazelisk.c
	cosmocc -o bbazelisk bbazelisk.c

bazelisk-darwin-arm64:
	curl -LO  https://github.com/bazelbuild/bazelisk/releases/download/v1.26.0/bazelisk-darwin-arm64
