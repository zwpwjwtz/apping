#ifndef I18N_H
#define I18N_H

#include <libintl.h>
#include <locale.h>
# ifdef APPING_DOMAIN
#   define _(x) dgettext(APT_DOMAIN,x)
#   define P_(msg,plural,n) dngettext(APT_DOMAIN,msg,plural,n)
# else
#   define _(x) gettext(x)
#   define P_(msg,plural,n) ngettext(msg,plural,n)
# endif
# define N_(x) x

#endif // I18N_H
