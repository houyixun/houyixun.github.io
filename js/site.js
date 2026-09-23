(() => {
  const path = location.pathname;
  document.querySelectorAll('#navbar a.nav-link').forEach(link => {
    const href = link.getAttribute('href');
    if (href && href !== '/' && path.startsWith(href) || href === '/' && path === '/') link.setAttribute('aria-current', 'page');
  });
  const toggle = document.getElementById('navbar-toggler-btn');
  if (toggle) toggle.setAttribute('aria-label', '展开或收起导航');
  document.querySelectorAll('[aria-label="Search"]').forEach(el => el.setAttribute('aria-label', '搜索文章'));
  document.querySelectorAll('[aria-label="Color Toggle"]').forEach(el => el.setAttribute('aria-label', '切换浅色与深色模式'));
})();
