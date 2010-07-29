#!/usr/bin/perl
use feature ':5.10';
use English;
use Regexp::Common;

our @wantClasses = qw(TextFieldEditor LocationFieldEditor WindowController
    BrowserWindowController WebViewPlus SearchableWebView BrowserWebView
    BrowserContentWebView);

my $binary = shift // '/Applications/Safari.app/Contents/MacOS/Safari';
my $arch = shift // 'x86_64';

# Get the desired class headers
local $RS;  # slurp
my $classRe = '^(' . join('|', @wantClasses) . ')$';
open my $classdump, '-|', qw(class-dump -Ia --arch), $arch,
    '-C', $classRe, $binary;
my $hdr = <$classdump>;
close $classdump;

# Remove struct definitions
$hdr =~ s/(#pragma mark Named Structures.*#pragma mark -)//s;
my $structs = $1;

# Turn class names to id
$hdr =~ s/^\s{4}\K
    ((?!NS|BOOL|id|int|unsigned|long|double|float|short|struct)\w.*)
    \s+\*(\w+);/id $2;/xmg;

# Remove RefPtr types
$hdr =~ s/(struct )?(WTF::)?(\w+Ptr)$RE{balanced}{-parens=>'<>'}/void*/g;

# Remove inline structs
$hdr =~ s/^\s{4}\K(struct \w+ $RE{balanced}{-parens=>'{}'} \*)/void*/msg;

# Remove OC++ methods
$hdr =~ s/^.*\.cxx_(con|de)struct.*$//mg;

# Remove all protocols, it seems this is safe?
$hdr =~ s/^\@interface.*\K<[^>]*>//mg;     # empty interfaces

# Remove WTF::Vector
$hdr =~ s/(struct )?(WTF::)?Vector<[^>]+?,\s*0\w{0,2}\s*>\s*\*/void*/g;
$hdr =~ s/(struct )?(WTF::)?Vector<[^>]+?,\s*0\w{0,2}\s*>\s*(\w+)/void *${3}[3]/g;

# Make some ivars public
$hdr =~ s/(\@interface LocationFieldEditor[^{]*\{)/$1\n\@public/sg;

print $hdr;
